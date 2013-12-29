#include "std.h"

Int string_to_i(const string str)
{
  int num; // 文字列を整数に変換するための変数 number

  sscanf(str, "%d", &num);
  
  return Int_init(num);
}

void string_get(charR str)
{
  charR tail; //入力した文字列の末尾をさすポインタ tail

  fgets(str, STRING_SIZE, stdin);
  tail = strchr(str, '\n');
  if (feof(stdin)) {
    puts("\n\n予期せぬ入力がありました!!");
    exit(EXIT_FAILURE);
  }

  if (!tail) {
    while (getchar() != '\n') {
      ;
    }
  } else { 
    *tail = '\0';
  }
}

static void string_put(const string str)
{
  fputs(str, stdout);
}

static void Mdealloc(String self)
{
  free(self);
}

static String Mset(String self, const string field)
{
  snprintf(self->field, STRING_SIZE, "%s", field);

  return self;
}

static Int Mto_i(String self)
{
  return string_to_i(self->field);
}

static String Mget(String self)
{
  string_get(self->field);

  return self;
}

static String Mput(String self)
{
  string_put(self->field);

  return self;
}

String String_new(void)
{
  String new = (String) malloc(sizeof(String_t)); // 新しいStringクラスのインスタンスのメモリを確保 new
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const String_t tmp = { // 読み取り専用であるインスタンスメソッドのポインタをnewに代入するための一時変数 temp
      .dealloc = Mdealloc,
      .set     = Mset,
      .to_i    = Mto_i,
      .get     = Mget,
      .put     = Mput,
    };
    
    *new = tmp;
  }

  return new;
}

String String_init(const string field)
{
  New(String, new); // 新しいインスタンスを生成 new
  Mset(new, field);

  return new;
}
