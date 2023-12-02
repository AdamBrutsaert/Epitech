#!/bin/bash

gcc -c *.c -I../../include
ar rcs libmy.a *.o
rm -f *.o
