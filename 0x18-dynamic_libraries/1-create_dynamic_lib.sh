#!/bin/bash
gccc -wall -wextra -werror -pedantic -C -fPIC *.c
gcc -shared -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
