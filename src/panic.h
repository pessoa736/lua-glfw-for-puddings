#ifndef PANIC
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define PANIC(L, ERROR, FORMAT, ...)\
{ \
    if (ERROR) \
    {\
        fprintf(stderr, "\n%s -> %s -> %i -> Error(%i): \n\t" FORMAT "\n\n", __FILE_NAME__, __FUNCTION__, __LINE__, ERROR, ##__VA_ARGS__);\
        raise(SIGABRT);\
        return luaL_error(L, FORMAT);\
    }\
}

#endif