#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 255           // 入力最大文字数(string型の大きさ)
typedef char string[STRING_SIZE]; // string型の定義
typedef string *stringR;          // string型のポインタ

typedef char *charR; // char型のポインタ

typedef int *intR; // int型のポインタ

// Classを定義するためのマクロ
#define Class(c) \
typedef struct _##c * const c; \
typedef struct _##c##List * c##List;

Class(String);                          // Stringクラスの宣言
String String_new(void);                // Stringクラスのインスタンスを生成
String String_init(const string field); // Stringクラスのインスタンスを生成し値をfieldで初期化

Class(Int);                    // Intクラスの宣言
Int Int_new(void);             // Intクラスのインスタンスを生成
Int Int_init(const int field); // Intクラスのインスタンスを生成し値をfieldで初期化
IntList IntList_new(void);     // IntListクラスのインスタンスを生成

#define Method *const // インスタンスメソッドを定義するマクロ

#include "../include/string.h"
#include "../include/int.h"

// インスタンスメソッドを簡単に使うためのシンタックスシュガー
#define Delete(s) (s->delete(s))
#define Set(s, d) (s->set(s, d))
#define To_i(s)   (s->to_i(s))
#define To_s(s)   (s->to_s(s))
#define Input(s)  (s->input(s))
#define Print(s)  (s->print(s))

#define GetR(s)   (s->getR(s))
#define Get(s)    (*GetR(s))

// インスタンスを生成するクラスメソッドを簡単に使うためのシンタックスシュガー
#define New(t, v) t v = t##_new()
#define Init(t, v, i) t v = t##_init(i)

#endif
