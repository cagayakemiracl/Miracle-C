#include "std.h"

String int_to_s(const int num)
{
  string str; // 整数を文字列に変換するための変数 string
  
  snprintf(str, STRING_SIZE, "%d", num);
  
  return String_init(str);
}

static void int_get(intR num)
{
  string str; // 入力した文字列を格納 string

  string_get(str);
  *num = 0;
  sscanf(str, "%d", num);
}

static void int_put(const int num)
{
  printf("%d", num);
}

static void Mdealloc(Int self)
{
  free(self);
}

static Int Mset(Int self, const int field)
{
  self->field = field;
  
  return self;
}

static String Mto_s(Int self)
{
  return int_to_s(self->field);
}

static Int Mget(Int self)
{
  int_get(&(self->field));

  return self;
}

static Int Mput(Int self)
{
  int_put(self->field);

  return self;
}

static Int Mdup(Int self)
{
  return Int_init(self->field);
}

static Int Lfirst(Int self)
{
  for ( ; self->prev; self = self->prev) {
    ;
  }

  return self;
}

static Int Llast(Int self)
{
  for ( ; self->next; self = self->next) {
    ;
  }

  return self;
}

static Int Lat(Int self, const int index)
{
  {
    int i; // 一時変数 index
    
    for (i = 0; self->next && (i < index); ++i, self = self->next) {
      ;
    }
  }

  return self;
}

static Int Lsize(Int self)
{
  Init(Int, size, 0); // selfのノードの数 大きさ size

  for ( ; self; ++(size->field), self = self->next) {
    ;
  }

  return size;
}

static Int Lset_at(Int self, const int field, const int index)
{
  Int p = Lat(self, index); // index要素のインスタンス

  Mset(p, field);

  return self;
}

static String Lto_s_at(Int self, const int index)
{
  index_m(Int, self, index, Mto_s);
}

static Int Lget_at(Int self, const int index)
{
  Int p = Lat(self, index); // index要素のインスタンス

  Mget(p);

  return self;
}

static Int Lput_at(Int self, const int index)
{
  Int p = Lat(self, index); // index要素のインスタンス

  Mput(p);

  return self;
}

static Int Lconcat(Int self, Int node)
{  
  if (!self) {
    self = node;
  } else {
    Int tail = Llast(self); // selfの最後の要素を指す tail
    tail->next = node;
    node->prev = tail;
  }

  return self;
}

static Int Lpush(Int self, const int field)
{
  return Lconcat(self, Int_init(field));
}

static Int Ladd(Int self)
{
  return Lconcat(self, Int_new());
}

static void Ldealloc(Int self)
{
  Int next; // 開放したインスタンスのnextポインタを保存 next

  while (self) {
    next = self->next;
    Mdealloc(self);
    self = next;
  }
}

#define each_fill(p) Mset(p, field);

static Int Lfill(Int self, const int field)
{
  {
    int bool; // selfのsizeが１かどうか boolean
    {
      Int size = Lsize(self); // selfのノードの数 size
      bool = (size->field == 1); 

      Dealloc(size);
    }
    
    if (bool) {
      Mset(self, field);
    } else {
      each_m(Int, self, each_fill);
    }
  }
  
  return self;
}

#define each_dup(p) copy = Lconcat(copy, Mdup(p)); \
  
static Int Ldup(Int self)
{
  Int copy = NULL; // selfと同じ内容のインスタンス

  each_m(Int, self, each_dup);
  
  return copy;
}

#define each_input(p, i) Put(i); Put(prompt); Mget(p);

static Int Linput(Int self)
{
  {
    int bool; // selfのsizeが１かどうか boolean
    {
      Int size = Lsize(self); // selfのノードの数 size
      bool = (size->field == 1);

      Dealloc(size);
    }
    
    if (bool) {
      Mget(self);
    } else {
      Init(String, prompt, " > "); // 入力時に表示するプロンプト prompt 
      each_with_index_m(Int, self, each_input);
      Dealloc(prompt);
    }
  }

  return self;
}

#define each_print(p) Mput(p); \
  if (p->next) {               \
  fputs(", ", stdout);         \
  }                            \

static Int Lprint(Int self)
{
  {
    int bool; // selfのsizeが１かどうか boolean
    {
      Int size = Lsize(self); // selfのノードの数 size
      bool = (size->field == 1);

      Dealloc(size);
    }
    
    if (bool) {
      Mput(self);
    } else {
      putchar('[');
      each_m(Int, self, each_print);
      putchar(']');
    }
  }

  return self;
}

static Int Leach(Int self, void (Method func)(Int self))
{
  each_m(Int, self, func);

  return self;
}

static Int LeachWI(Int self, void (Method func)(Int self, Int index))
{
  each_with_index_m(Int, self, func);

  return self;
}

static Int Lgenesis(Int self, Int node)
{
  self->child = node;

  return self;
}

#define each_unite(p) p->child = Ldup(node);

static Int Lunite(Int self, Int node)
{
  each_m(Int, self, each_unite);

  return self;
}

#define each_aquarion(p) p->child = Int_newA(index);

static Int Laquarion(Int self, const int index)
{
  each_m(Int, self, each_aquarion);

  return self;
}

array_method_void(Int, dealloc);
array_method(Int, input);
array_method_two(Int, fill, const int field, field);
array_method_two(Int, aquarion, const int index, index);
array_method_two(Int, each, void (Method func)(Int self), func);

static Int Agenesis(Int self, Int node)
{
  if (self->child) {
    return Lgenesis(self, node);
  }

  return Agenesis(self->child, node);
}

static Int Adup(Int copy, Int self);
static Int Tdup(Int copy, Int self)
{
  if (self->child == self) {
    return copy;
  }
    
  copy->child = Ldup(self->child);
  Adup(copy->child, self->child);
  if (self->next) {
    return Tdup(copy->next, self->next);
  }

  return copy;
}

static Int Adup(Int copy, Int self)
{
  if (self->child == self) {
    return copy;
  }
  
  copy->child = Ldup(self->child);
  Tdup(copy->child, self->child);
  if (self->next) {
    return Adup(copy->next, self->next);
  }

  return copy;
}

static Int Sdup(Int self)
{
  Int copy = Ldup(self);
  if (self->child == self) {
    return copy;
  }
  
  Adup(copy, self);

  return copy;
}
  
static Int Aprint(Int self);
static Int Tprint(Int self)
{
  if (self->child == self) {
    Lprint(self);
  } else {
    if (!self->prev) {
      putchar('[');
    }
    
    Aprint(self->child);
    if (self->next) {
      fputs(", ", stdout);
      return Tprint(self->next);
    } else {
      putchar(']');
    }
  }

  return self;
}

static Int Aprint(Int self)
{
  if (self->child == self) {
    Lprint(self);
  } else {
    if (!self->prev) {
      putchar('[');
    }
    
    Tprint(self->child);
    if (self->next) {
      fputs(", ", stdout);
      return Aprint(self->next);
    } else {
      putchar(']');
    }
  }

  return self;
}

static Int Sprint(Int self)
{
  Aprint(self);
  putchar('\n');
  
  return self;
}

Int Int_new(void)
{
  Int new = (Int) malloc(sizeof(Int_t)); // 新しいIntクラスのインスタンスのメモリを確保 new
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .prev = NULL,
      .next = NULL,
      .child = new,
      
      .set  = Mset,
      .to_s = Mto_s,
      .get  = Mget,
      .put  = Mput,
      
      .first = Lfirst,
      .last  = Llast,
      .at    = Lat,
      .size  = Lsize,
      
      .set_at  = Lset_at,
      .to_s_at = Lto_s_at,
      .get_at  = Lget_at,
      .put_at  = Lput_at,

      .concat   = Lconcat,
      .push     = Lpush,
      .add      = Ladd,
      .genesis  = Agenesis,
      .unite    = Lunite,
      .aquarion = Aaquarion,
      
      .dealloc = Adealloc,
      .fill    = Afill,
      .dup     = Sdup,
      .input   = Ainput,
      .print   = Sprint,
      
      .each   = Aeach,
      .eachWI = LeachWI,
    };

    *new = tmp;
  }

  return new;
}

Int Int_init(const int field)
{
  New(Int, new); // 新しいインスタンスを生成 new
  Set(new, field);

  return new;
}

Int Int_newA(const int index)
{
  Int new = NULL; // 新しいインスタンスを生成 new
  {
    int i;

    for (i = 0; i < index; ++i) {
      new = Ladd(new);
    }
  }

  return new;
}
