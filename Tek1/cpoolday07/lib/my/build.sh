#!/bin/bash

gcc -c *.c
ar rcs libmy.a *.o
rm -f *.o
