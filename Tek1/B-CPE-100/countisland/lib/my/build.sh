#!/bin/bash

echo "void foo(){}" > temp.c
gcc temp.c -shared -olibmy.a
rm -f temp.c
