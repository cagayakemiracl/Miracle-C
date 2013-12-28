#include "std.h"

String int_to_s(const int num)
{
  string str; // 整数を文字列に変換するための変数 string
  
  snprintf(str, STRING_SIZE, "%d", num);
  
  return String_init(str);
}

static void int_input(intR num)
{
  string str; // 入力した文字列を格納 string

  string_input(str);
  *num = 0;
  sscanf(str, "%d", num);
}

static void int_print(const int num)
{
  printf("%d", num);
}

static void Mdelete(Int self)
{
  free(self);
}

static intR MgetR(Int self)
{
  return &(self->field);
}

static int Mget(Int self)
{
  return self->field;
}

static Int Mset(Int self, const int field)
{
  {
    *MgetR(self) = field;
  }
  
  return self;
}

static String Mto_s(Int self)
{
  return int_to_s(Mget(self));
}

static Int Minput(Int self)
{
  {
    int_input(MgetR(self));
  }

  return self;
}

static Int Mprint(Int self)
{
  {
    int_print(Mget(self));
  }

  return self;
}

static void Ldelete(Int self)
{
  Int next;

  while (self) {
    next = self->next;
    Mdelete(self);
    self = next;
  }
}

static Int Lfirst(Int self)
{
  {
    for ( ; self->prev; self = self->prev) {
      ;
    }
  }

  return self;
}

static Int Llast(Int self)
{
  {
    for ( ; self->next; self = self->next) {
      ;
    }
  }

  return self;
}

static Int Lsize(Int self)
{
  Init(Int, i, 0);

  for ( ; self; ++Get(i, 0), self = self->next) {
    ;
  }

  return i;
}
    
static Int Lselect(Int self, const int num)
{
  {
    int i; // 一時変数
    
    for (i = 0; self->next && (i < num); ++i, self = self->next) {
      ;
    }
  }

  return self;
}

static intR LgetR(Int self, const int index)
{
  self = Lselect(self, index);

  return MgetR(self);
}

static int Lget(Int self, const int index)
{
  self = Lselect(self, index);

  return Mget(self);
}

static Int Lset(Int self, const int index, const int num)
{
  self = Lselect(self, index);

  return Mset(self, num);
}

static String Lto_s(Int self, const int index)
{
  self = Lselect(self, index);

  return Mto_s(self);
}

static Int Lpush(Int self)
{
  {
    New(Int, new); // 末尾に追加するインスタンスを生成

    if (!self) {
      self = new;
    } else {
      Int tail = Llast(self); // selfの最後の要素を指す tail
      tail->next = new;
      new->prev = tail;
    }
  }
  
  return self;
}

static Int Lprint(Int self)
{
  {
    Int p;
    Init(String, l, "[ ");
    Init(String, r, "] ");

    Print(l)->delete(l);
    for (p = self; p; p = p->next) {
      Mprint(p); putchar(' ');
    }
    
    Print(r)->delete(r);
  }

  return self;
}

static Int Linput(Int self)
{
  {
    Int p;
    Init(Int, i, 0);
    Init(String, c, " > ");

    for (p = self; p; ++Get(i, 0), p = p->next) {
      Print(i); Print(c);
      Minput(p);
    }

    Delete(i); Delete(c);
  }

  return self;
}

Int Int_new(void)
{
  Int new = (Int) malloc(sizeof(Int_t)); // 新しいStringクラスのインスタンスのメモリを確保 new
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .prev   = NULL,
      .next   = NULL,
      .self   = new,
      .delete = Ldelete,
      .getR   = LgetR,
      .get    = Lget,
      .set    = Lset,
      .first  = Lfirst,
      .last   = Llast,
      .select = Lselect,
      .size   = Lsize,
      .to_s   = Lto_s,
      .input  = Linput,
      .print  = Lprint,
      .push   = Lpush,
    };

    *new = tmp;
  }

  return new;
}

Int Int_init(const int num)
{
  New(Int, new);
  Set(new, 0, num);

  return new;
}
