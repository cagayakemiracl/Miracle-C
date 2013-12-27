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

Int Int_new(void)
{
  Int new = (Int) malloc(sizeof(Int_t)); // 新しいStringクラスのインスタンスのメモリを確保 new
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .delete = Mdelete,
      .getR   = MgetR,
      .get    = Mget,
      .set    = Mset,
      .to_s   = Mto_s,
      .input  = Minput,
      .print  = Mprint,
    };

    *new = tmp;
  }

  return new;
}

Int Int_init(const int field)
{
  New(Int, new);
  Mset(new, field);

  return new;
}

static void Ldelete(IntList self)
{
  IntList next;

  while (self) {
    next = self->next;
    Delete(self->field);
    free(self);
    self = next;
  }
}

static IntList LgetTail(IntList self)
{
  {
    for ( ; self->next; self = self->next) {
      ;
    }
  }

  return self;
}

static IntList Lselect(IntList self, const int num)
{
  {
    int i; // 一時変数
    
    for (i = 0; self->next && (i < num); ++i, self = self->next) {
      ;
    }
  }

  return self;
}

static IntList Ladd(IntList self)
{
  {
    New(IntList, new); // 末尾に追加するインスタンスを生成

    if (!self) {
      self = new;
    } else {
      IntList tail = LgetTail(self); // selfの最後の要素を指す tail
      tail->next = new;
      new->prev = tail;
    }
  }
  
  return self;
}

IntList IntList_new(void)
{
  IntList new = (IntList) malloc(sizeof(IntList_t)); // 新しいIntListクラスのインスタンスのメモリを確保 new
   if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const IntList_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .prev    = NULL,
      .next    = NULL,
      .field   = Int_new(),
      .delete  = Ldelete,
      .getTail = LgetTail,
      .select  = Lselect,
      .add     = Ladd,
    };

    *new = tmp;
  }

  return new;
}
