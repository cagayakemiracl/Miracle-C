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
typedef struct _##c * c; \

Class(String);                          // Stringクラスの宣言
String String_new(void);                // Stringクラスのインスタンスを生成
String String_init(const string field); // Stringクラスのインスタンスを生成し値をfieldで初期化

Class(Int);                    // Intクラスの宣言
Int Int_new(void);             // Intクラスのインスタンスを生成
Int Int_init(const int field); // Intクラスのインスタンスを生成し値をfieldで初期化
Int Int_arrayNew(const int index);

#define Method *const // インスタンスメソッドを定義するマクロ

#define each_m(type, self, func)                  \
  {                                             \
    type p;                                     \
    for (p = self; p; p = p->next) {            \
      func(p);                                  \
    }                                           \
  }                                             \
    
#define each_with_index_m(type, self, func)       \
  {                                             \
    type p;                                     \
    Init(Int, i, 0);                            \
    for (p = self; p; ++Get(i), p = p->next) {  \
      func(p, i);                               \
    }                                           \
    Delete(i);                                  \
  }                                             \

#define index_m(type, self, index, func)          \
  type t = Element(self, index);                  \
  return func(t);                                 \
    
#define index_two_m(type, self, index, func, field)      \
  type t = Element(self, index);                         \
  return func(t, field);                                 \
    
#include "../include/string.h"
#include "../include/int.h"

// インスタンスメソッドを簡単に使うためのシンタックスシュガー
#define Delete(s) (s->delete(s))
#define GetR(s)   (s->getR(s))
#define Get(s)    (*GetR(s))
#define Set(s, d) (s->set(s, d))
#define To_i(s)   (s->to_i(s))
#define To_s(s)   (s->to_s(s))
#define Input(s)  (s->input(s))
#define Print(s)  (s->print(s))

#define First(s)      (s->first(s))
#define Last(s)       (s->last(s))
#define Element(s, n) (s->element(s, n))
#define Size(s)       (s->size(s))

#define GetRI(s, i)   (s->getRI(s, i))
#define GetI(s, i)    (*GetRI(s, i))
#define SetI(s, i, d) (s->setI(s, i, d))
#define To_sI(s, i)   (s->to_sI(s, i))
#define PrintI(s, i)  (s->printI(s, i))
#define InputI(s, i)  (s->inputI(s, i))

#define Push(s)   (s->push(s))
#define InputA(s) (s->inputA(s))
#define PrintA(s) (s->printA(s))

// インスタンスを生成するクラスメソッドを簡単に使うためのシンタックスシュガー
#define New(t, v) t v = t##_new()
#define Init(t, v, i) t v = t##_init(i)
#define ArrayNew(t, v, i) t v = t##_arrayNew(i)

#endif
