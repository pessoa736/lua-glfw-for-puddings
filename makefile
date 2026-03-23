
BUILD_PATH = ./build/
BINARYNAME = lgfp.so


COMPLUAINCLUDE = -I/usr/include/lua -llua -lm -ldl
COMPGLFWINCLUDE = -lglfw -lX11 -lpthread -lXrandr -lXi

compGCCARGS = -Wimplicit-function-declaration -shared -fpic

COMPARGS = $(compGCCARGS) $(COMPLUAINCLUDE) $(COMPGLFWINCLUDE)

all: clean compile test

compile:
	gcc ./src/*.c $(COMPARGS) -o $(BUILD_PATH)$(BINARYNAME) 
       
clean:
	rm -rf $(BUILD_PATH)$(BINARYNAME)

test: 
	lua ./__test__/createWindows.lua

