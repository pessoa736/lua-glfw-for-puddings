#ifndef SETUPLUA_H
#define SETUPLUA_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int LTerminateGLFW(lua_State* L);

int LGLFWIsInitialized(lua_State *L);

#endif