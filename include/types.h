#ifndef TYPES_H
#define TYPES_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <GLFW/glfw3.h>

typedef const  char *string;

typedef const struct luaL_Reg LR;

typedef GLFWwindow *GWindow;


typedef struct {
    GWindow window;
    int width;
    int heigth;
    char* title;
} LuaWindows;




#define neoTypeOf(x) _Generic(\
    (x),\
    int: "int",\
    float: "float",\
    double: "double", \
    string: "string", \
    char*: "string", \
    char: "char", \
    GWindow: "GWindow" \
)

#endif