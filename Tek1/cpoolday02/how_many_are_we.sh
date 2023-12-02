#!/bin/bash

cut -d';' -f3 | grep -i "$1" | wc -l
