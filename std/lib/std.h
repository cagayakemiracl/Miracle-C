#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

#include "../../object/lib/object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 255           // 入力最大文字数(string型の大きさ)
typedef char string[STRING_SIZE]; // string型の定義
typedef string *stringR;          // string型のポインタ

typedef char *charR; // char型のポインタ

typedef int *intR; // int型のポインタ

Class(String, string);         // Stringクラスの宣言
Class(Int, int);               // Intクラスの宣言

#include "../include/string.h"
#include "../include/int.h"

#endif
