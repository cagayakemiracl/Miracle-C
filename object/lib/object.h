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
    
#define each_with_index_m(type, self, func)       \
  {                                               \
    type p;                                       \
    Init(Int, i, 0);                              \
    for (p = self; p; ++i->field, p = p->next) {  \
      func(p, i);                                 \
    }                                             \
    Dealloc(i);                                   \
  }                                               \

#define index_m(type, self, index, func)        \
  type t = At(self, index);                     \
  return func(t);                               \
    
#define index_two_m(type, self, index, func, field) \
  type t = At(self, index);                         \
  return func(t, field);                            \
    
// インスタンスメソッドを簡単に使うためのシンタックスシュガー
#define Set(s, d) (s->set(s, d))
#define To_i(s)   (s->to_i(s))
#define To_s(s)   (s->to_s(s))
#define get(s)    (s->get(s))
#define Put(s)    (s->put(s))

#define First(s) (s->first(s))
#define Last(s)  (s->last(s))
#define At(s, n) (s->at(s, n))
#define Size(s)  (s->size(s))

#define Set_at(s, i, d) (s->set_at(s, i, d))
#define To_s_at(s, i)   (s->to_s_at(s, i))
#define Get_at(s, i)   (s->Get_at(s, i))
#define Put_at(s, i)  (s->put_at(s, i))

#define Concat(s, d) (s->concat(s, d))
#define Push(s, d)   (s->push(s, d))

#define Dealloc(s) (s->dealloc(s))
#define Fill(s, d) (s->fill(s, d))
#define Dup(s)     (s->dup(s))
#define Input(s)   (s->input(s))
#define Print(s)  (s->print(s))

#define Each(s, f)   (s->each(s, f))
#define EachWI(s, f) (s->eachWI(s, f))
  
// インスタンスを生成するクラスメソッドを簡単に使うためのシンタックスシュガー
#define New(t, v) t v = t##_new()
#define Init(t, v, i) t v = t##_init(i)
#define ArrayNew(t, v, i) t v = t##_newA(i)

#endif
