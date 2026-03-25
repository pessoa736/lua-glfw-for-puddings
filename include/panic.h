#ifndef PANIC
    #include <stdio.h>
    #include <signal.h>
    #include <stdlib.h>

    #define PANIC(ERROR, FORMAT, ...)\
    do { \
        if (ERROR) \
        {\
            fprintf(stderr, "\n%s -> %s -> %i -> Error(%i): \n\t" FORMAT "\n\n", __FILE_NAME__, __FUNCTION__, __LINE__, ERROR, ##__VA_ARGS__);\
            raise(SIGABRT);\
        }} while(0);

#endif


#ifndef LuaPANIC
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>

    #define LuaPANIC(L, ERROR, FORMAT, ...)\
    do { \
        if (ERROR) \
        {\
            lua_Debug ar; \
            if (lua_getstack(L, 1, &ar)){ \
                lua_getinfo(L, "nSl", &ar);\
                \
                const char *func = ar.name ? ar.name : "main";\
                \
                fprintf(stderr,\
                    "\n%s -> %s -> %d -> Error(%d): \n\t" FORMAT "\n\n",\
                    ar.short_src,\
                    func, \
                    ar.currentline, \
                    ERROR, \
                    ##__VA_ARGS__\
                );\
                lua_close(L);\
                L = NULL; \
            } else { \
                fprintf(stderr,\
                    "unknown.lua -> ? -> 0 -> %s:\n\t" FORMAT,\
                    ##__VA_ARGS__\
                );\
                \
                lua_close(L);\
                L = NULL; \
            }}} while(0);

#endif