#!/bin/sh
autoscan
aclocal
autoconf
autoheader
automake --add-missing
./configure CFLAGS="-g -O2 -lm -Wall"
make
