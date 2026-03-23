#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "types.h"
#include "window.h"
#include "panic.h"


int LlgfpIsInitialized(lua_State *L){
    int res = glfwInit();
    lua_pushboolean(L, res);
    return 1;
}


int LCreateWindowsMetatable(lua_State *L){
    luaL_newmetatable(L, "LGFP.WindowManager");

    lua_pushvalue(L, -1);

    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, LMakeCurrentWindows);
    lua_setfield(L, -2, "makeContextCurrent");

    lua_pushcfunction(L, LCloseWindows);
    lua_setfield(L, -2, "__gc");

    lua_pushcfunction(L, LShouldCloseWindows);
    lua_setfield(L, -2, "ShouldClose");

    lua_pop(L, 1);
}




static LR Lfunctions [] ={
    {"CreateWindows", LCreateWindow},
    {NULL, NULL},
};




int luaopen_lgfp(lua_State* L){
    PANIC(L, !glfwInit(), "GLFW not initialized or not instaled");
    LCreateWindowsMetatable(L);

    lua_newtable(L);

    luaL_newlib(L, Lfunctions);
    lua_setfield(L, -2, "WindowManager");

    return 1;
}

