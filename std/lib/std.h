#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 255 // 入力最大文字数
typedef char string[STRING_SIZE]; // string型の定義
typedef string *stringR;

typedef char *charR;

typedef int *intR;

#define Class(c) typedef struct _##c * const c

Class(String);
String String_init(const string field);
String String_new(void);

Class(Int);
Int Int_init(const int field);
Int Int_new(void);

#define Method *const

#include "../include/string.h"
#include "../include/int.h"

#define Delete(s) (s->delete(s))
#define Set(s, d) (s->set(s, d))
#define To_i(s)   (s->to_i(s))
#define To_s(s)   (s->to_s(s))
#define Input(s)  (s->input(s))
#define Print(s)  (s->print(s))

#define GetR(s)   (s->getR(s))
#define Get(s)    (*GetR(s))

#define Init(t, v, i) t v = t##_init(i)
#define New(t, v) t v = t##_new()

#endif
