#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "types.h"
#include "window.h"


int LlgfpIsInitialized(lua_State *L){
    lua_pushboolean(L, glfwInit());
    return 1;
}




static LR Lfunctions [] ={
    {"IsInitialized", LlgfpIsInitialized},
    {"CreateWindows", LCreateWindow},
    {NULL, NULL},
};




int luaopen_lgfp(lua_State* L){
    luaL_newlib(L, Lfunctions);
    return 1;
}

