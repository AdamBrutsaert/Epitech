#!/bin/bash

git add *

if [ "$#" -eq 0 ]; then
	git commit -m "push_that commit"
else
	git commit -m "$1"
fi

git push
