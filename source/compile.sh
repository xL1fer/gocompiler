#!/bin/sh

# run lex and compile the resulting C analyser
lex gocompiler.l
yacc -d gocompiler.y
clang-7 -o gocompiler y.tab.c lex.yy.c functions.c
./gocompiler

# 'lex' and 'gcc' are commonly available too