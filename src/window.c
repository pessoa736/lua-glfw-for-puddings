#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "window.h"
#include "panic.h"



int LCreateWindow(lua_State *L){
    PANIC(L, !glfwInit(), "GLFW not initialized")
    int width  = luaL_checknumber(L, 1);
    int heigth = luaL_checknumber(L, 2);
    
    string title = luaL_checkstring(L, 3);
    
    GWindow win = glfwCreateWindow(width, heigth, title, NULL, NULL);

    PANIC(L, !win, "failed to create GLFW windows");

    LuaWindows ud = (LuaWindows )lua_newuserdata(L, sizeof(LuaWindows));
    ud->window = win;

    PANIC(L, !ud, "not created userdata");

    luaL_getmetatable(L, "LGFP");
    lua_setmetatable(L, -2);

    return 1;
}
