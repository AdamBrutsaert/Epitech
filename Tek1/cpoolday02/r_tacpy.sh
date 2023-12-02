#!/bin/bash

sed -n "n;p" | cut -d':' -f1 | rev | sort -r | sed -n "$MY_LINE1,$MY_LINE2 p" | sed -z "s/\n/, /g" | sed "s/, $/.\n/g"
