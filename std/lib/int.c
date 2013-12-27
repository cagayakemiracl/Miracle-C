#include "std.h"

String int_to_s(const int num)
{
  string str; // 整数を文字列に変換するための変数
  
  snprintf(str, STRING_SIZE, "%d", num);
  
  return String_init(str);
}

static void int_input(intR num)
{
  string s; // 入力した文字列を格納 string

  string_input(s);
  *num = 0;
  sscanf(s, "%d", num);
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

Int Int_init(const int field)
{
  Int new = (Int) malloc(sizeof(Int_t)); // 新しいStringクラスのインスタンスのメモリを確保
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数
      .delete = Mdelete,
      .getR   = MgetR,
      .get    = Mget,
      .set    = Mset,
      .to_s   = Mto_s,
      .input  = Minput,
      .print  = Mprint,
    };

    *new = tmp;
    Mset(new, field);
  }

  return new;
}

Int Int_new(void)
{
  return Int_init(0);
}
