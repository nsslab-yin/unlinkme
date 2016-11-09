#!/bin/bash

echo \#define C_SIZE_0 AAAA > config.h
echo \#define C_SIZE_1 BBBB >> config.h
echo \#define C_SIZE_2 CCCC >> config.h

declare -a size_list=(64 72 80 88 96 104 112 120 128)

c0=$[$RANDOM % ${#size_list[@]}]
c1=$[$RANDOM % ${#size_list[@]}]
c2=$[$RANDOM % ${#size_list[@]}]

sed -i 's/AAAA/'${size_list[$c0]}'/' "config.h"
sed -i 's/BBBB/'${size_list[$c1]}'/' "config.h"
sed -i 's/CCCC/'${size_list[$c2]}'/' "config.h"

gcc -m32 -o unlink_me unlink_me.c
