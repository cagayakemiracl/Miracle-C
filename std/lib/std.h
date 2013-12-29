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

Class(String);                          // Stringクラスの宣言
String String_new(void);                // Stringクラスのインスタンスを生成
String String_init(const string field); // Stringクラスのインスタンスを生成し値をfieldで初期化

Class(Int);                    // Intクラスの宣言
Int Int_new(void);             // Intクラスのインスタンスを生成
Int Int_init(const int field); // Intクラスのインスタンスを生成し値をfieldで初期化
Int Int_newA(const int index); // Intkクラスの配列インスタンスを生成

#include "../include/string.h"
#include "../include/int.h"

#endif
