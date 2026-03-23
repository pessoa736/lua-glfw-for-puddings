#ifndef TYPES_H
#define TYPES_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>


typedef const struct luaL_Reg LR;


typedef GLFWwindow *GWindow;

typedef struct {
    GWindow window;
} *LuaWindows;


typedef const char* string;

#endif