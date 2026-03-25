#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "types.h"
#include "window.h"
#include "panic.h"


int LGLFWInit(lua_State *L){
    int res = glfwInit();
    lua_pushboolean(L, (int)res);
    return 1;
}

int LTerminateGLFW(lua_State *L){
    glfwTerminate();
    return 0;
}



static LR Lfunctions [] ={
    {"CreateWindows", LCreateWindow},
    {NULL, NULL},
};




int luaopen_lgfp(lua_State* L){
    LCreateWindowsMetatable(L);

    lua_newtable(L);

    luaL_newlib(L, Lfunctions);
    lua_setfield(L, -2, "WindowManager");

    lua_pushcfunction(L, LGLFWInit);
    lua_setfield(L, -2, "Init");
    lua_pushcfunction(L, LTerminateGLFW);
    lua_setfield(L, -2, "Terminate");


    return 1;
}

