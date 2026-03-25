#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>
#include "types.h"
#include "window.h"
#include "panic.h"



int LCreateWindow(lua_State *L)
{
    
    LuaWindows *ud = (LuaWindows *)lua_newuserdata(L, sizeof(LuaWindows));

    LuaPANIC(L, ud == NULL,"memory not allocated");
    

    ud->width  = luaL_checknumber(L, 1);
    ud->heigth = luaL_checknumber(L, 2);
    
    string title = luaL_checkstring(L, 3);
    ud->title = strdup(title);

    LuaPANIC(L, !(ud->width>0), "expected width to be greater than 0. current width: %d", ud->width);
    LuaPANIC(L, !(ud->heigth>0), "expected heigth to be greater than 0. current height: %d", ud->heigth);
    LuaPANIC(L, !(neoTypeOf(ud->title)=="string"), "expected a string in 3# arg");
        
    
    GWindow win = glfwCreateWindow(ud->width, ud->heigth, ud->title, NULL, NULL);
    
    if (win){
        ud->window = win;
    }else{
        glfwTerminate();
        LuaPANIC(L, 1, "failed to create GLFW windows");
        return 0;
    }

    luaL_getmetatable(L, "LGFP.WindowManager");
    lua_setmetatable(L, -2);

    return 1;
}

int LMakeCurrentWindows(lua_State *L){
    LuaWindows *ud  = luaL_checkudata(L, 1, "LGFP.WindowManager");

    glfwMakeContextCurrent(ud->window);

    return 0;
}


//__gc
int LCloseWindows(lua_State *L)
{
    LuaWindows *ud = (LuaWindows *)lua_newuserdata(L, sizeof(LuaWindows));
    LuaPANIC(L, ud == NULL, "not get Window or no memory");
    ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    if (ud)
    {
        glfwDestroyWindow(ud->window);
        free(ud->title);
        ud->title = NULL;
    }

    return 0;
}


int LShouldCloseWindows(lua_State *L){
    LuaWindows *ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    int res = glfwWindowShouldClose(ud->window);

    lua_pushboolean(L, res);

    return 1;
}


int LGetWidthWindows(lua_State *L){
    LuaWindows *ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    LuaPANIC(L, !ud, "not found window")
    
    lua_pushinteger(L, (int)ud->width);

    return 1;
}

int LGetHeightWindows(lua_State *L){
    LuaWindows *ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    LuaPANIC(L, !ud, "not found window")
    
    lua_pushinteger(L, (int)ud->heigth);

    return 1;
}

int LGetTitleWindows(lua_State *L){
    LuaWindows *ud = luaL_checkudata(L, 1, "LGFP.WindowManager");

    LuaPANIC(L, !ud, "not found window")
    
    printf("%s\n", ud->title);
    lua_pushstring(L, ud->title);

    return 1;
}


int LCreateWindowsMetatable(lua_State *L)
{
    luaL_newmetatable(L, "LGFP.WindowManager");

    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, LMakeCurrentWindows);
    lua_setfield(L, -2, "MakeContextCurrent");

    lua_pushcfunction(L, LCloseWindows);
    lua_setfield(L, -2, "__gc");

    lua_pushcfunction(L, LShouldCloseWindows);
    lua_setfield(L, -2, "ShouldClose");

    lua_pushcfunction(L, LGetWidthWindows);
    lua_setfield(L, -2, "GetWidth");

    lua_pushcfunction(L, LGetHeightWindows);
    lua_setfield(L, -2, "GetHeight");

    lua_pushcfunction(L, LGetTitleWindows);
    lua_setfield(L, -2, "GetTitle");

    lua_pop(L, 1);
}