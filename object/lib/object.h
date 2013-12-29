#ifndef _OBJECT_H_INCLUDED_
#define _OBJECT_H_INCLUDED_

// Classを定義するためのマクロ
#define Class(c) \
typedef struct _##c * c; \

#define Method *const // インスタンスメソッドを定義するマクロ

#define each_m(type, self, func)                \
  {                                             \
    type p;                                     \
    for (p = self; p; p = p->next) {            \
      func(p);                                  \
    }                                           \
  }                                             \
    
#define each_with_index_m(type, self, func)     \
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
#define ArrayNew(t, v, i) t v = t##_newA(i)

#endif
