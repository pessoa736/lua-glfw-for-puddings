#ifndef WINDOW_H
#define WINDOW_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>
#include "types.h"


int LCreateWindow(lua_State *L);

int LMakeCurrentWindows(lua_State *L);

int LCloseWindows(lua_State *L);

int LShouldCloseWindows(lua_State *L);

int LCreateWindowsMetatable(lua_State *L);

#endif