
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "window.h"
#include "panic.h"



int LCreateWindow(lua_State *L){
    int width  = luaL_checknumber(L, 1);
    int heigth = luaL_checknumber(L, 2);
    
    string title = luaL_checkstring(L, 3);
    
    GWindow win = glfwCreateWindow(width, heigth, title, NULL, NULL);

    PANIC(L, !win, "failed to create GLFW windows");

    LuaWindows ud = (LuaWindows )lua_newuserdata(L, sizeof(LuaWindows));
    ud->window = win;

    PANIC(L, !ud, "not created userdata");

    luaL_getmetatable(L, "LGFP.WindowManager");
    lua_setmetatable(L, -2);

    return 1;
}

int LMakeCurrentWindows(lua_State *L){
    LuaWindows ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    glfwMakeContextCurrent(ud->window);

    return 0;
}

int LCloseWindows(lua_State *L){
    LuaWindows ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    if (ud->window){
        glfwDestroyWindow(ud->window);
        ud->window = NULL;
    }

    return 0;
}


int LShouldCloseWindows(lua_State *L){
    LuaWindows ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    int res = glfwWindowShouldClose(ud->window);

    lua_pushboolean(L, res);

    return 1;
}