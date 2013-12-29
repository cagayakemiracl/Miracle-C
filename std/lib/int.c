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
  *MgetR(self) = field;
  
  return self;
}

static String Mto_s(Int self)
{
  return int_to_s(Mget(self));
}

static Int Minput(Int self)
{
  int_input(MgetR(self));

  return self;
}

static Int Mprint(Int self)
{
  int_print(Mget(self));

  return self;
}

static void Ldelete(Int self)
{
  Int next; // 開放したインスタンスのnextポインタを保存 next

  while (self) {
    next = self->next;
    Mdelete(self);
    self = next;
  }
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

static Int Lelement(Int self, const int num)
{
  {
    int i; // 一時変数 index
    
    for (i = 0; self->next && (i < num); ++i, self = self->next) {
      ;
    }
  }

  return self;
}

static Int Lsize(Int self)
{
  Init(Int, size, 0); // selfのノードの数 大きさ size

  for ( ; self; ++Get(size), self = self->next) {
    ;
  }

  return size;
}

static intR LgetRI(Int self, const int index)
{
  index_m(Int, self, index, MgetR);
}

static int LgetI(Int self, const int index)
{
  index_m(Int , self, index, Mget);
}

static Int LsetI(Int self, const int index, const int field)
{
  index_two_m(Int, self, index, Mset, field);
}

static String Lto_sI(Int self, const int index)
{
  index_m(Int, self, index, Mto_s);
}

static Int LprintI(Int self, const int index)
{
  index_m(Int, self, index, Mprint);
}

static Int LinputI(Int self, const int index)
{
  index_m(Int, self, index, Minput);
}

static Int Lpush(Int self)
{
  {
    New(Int, new); // 末尾に追加するインスタンスを生成 new

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

static Int Leach(Int self, void (Method func)(Int self))
{
  each_m(Int, self, func);

  return self;
}

static Int LeachI(Int self, void (Method func)(Int self, Int index))
{
  each_with_index_m(Int, self, func);

  return self;
}

static void each_print(Int self)
{
  Mprint(self); putchar(' ');
}

static Int Lprint(Int self)
{
  {
    Int size = Lsize(self); // selfのノードの数 size
  
    if (Mget(size) == 1) {
      Mprint(self);
    } else {
      Init(String, left, "[ ");  // 配列の左括弧 left bracket
      Init(String, right, "] "); // 配列の右括弧 right bracket

      Print(left)->delete(left);
      Leach(self, each_print);
      Print(right)->delete(right); putchar('\n');
    }
  }

  return self;
}

#define each_input(self, i) Print(i); Print(prompt); Minput(p);

static Int Linput(Int self)
{
  {
    Int size = Lsize(self); // selfのノードの数 size

    if (Mget(size) == 1) {
      Minput(self);
    } else {
      Init(String, prompt, " > "); // 入力時に表示するプロンプト prompt 
      each_with_index_m(Int, self, each_input);
      Delete(prompt);
    }
  }

  return self;
}

Int Int_new(void)
{
  Int new = (Int) malloc(sizeof(Int_t)); // 新しいIntクラスのインスタンスのメモリを確保 new
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .prev    = NULL,
      .next    = NULL,
      .self    = new,
      
      .delete  = Ldelete,
      .getR    = MgetR,
      .get     = Mget,
      .set     = Mset,
      .to_s    = Mto_s,
      .input   = Minput,
      .print   = Mprint,
      
      .first   = Lfirst,
      .last    = Llast,
      .element = Lelement,
      .size    = Lsize,
      
      .getRI   = LgetRI,
      .getI    = LgetI,
      .setI    = LsetI,
      .to_sI   = Lto_sI,
      .inputI  = LinputI,
      .printI  = LprintI,
      
      .push    = Lpush,
      .inputA  = Linput,
      .printA  = Lprint,
      
      .each    = Leach,
      .eachI   = LeachI,
    };

    *new = tmp;
  }

  return new;
}

Int Int_init(const int num)
{
  New(Int, new); // 新しいインスタンスを生成 new
  Set(new, num);

  return new;
}

Int Int_newA(const int index)
{
  New(Int, new); // 新しいインスタンスを生成 new
  
  {
    int i;

    for (i = 1; i < index; ++i) {
      Push(new);
    }
  }

  return new;
}
