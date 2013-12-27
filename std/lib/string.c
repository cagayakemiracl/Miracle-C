#include "std.h"

Int string_to_i(const string str)
{
  int num;

  sscanf(str, "%d", &num);
  
  return Int_init(num);
}

void string_input(charR str) // string型の標準入力関数
{
  charR t; //入力した文字列の末尾をさすポインタ tail

  fgets(str, STRING_SIZE, stdin);
  t = strchr(str, '\n');
  if (feof(stdin)) {
    puts("\n\n予期せぬ入力がありました!!");
    exit(EXIT_FAILURE);
  }

  if (!t) {
    while (getchar() != '\n') {
      ;
    }
  } else { 
    *t = '\0';
  }
}

static void string_print(const string str)
{
  fputs(str, stdout);
}

static void Mdelete(String self)
{
  free(self);
}

static stringR MgetR(String self)
{
  return &(self->field);
}

static charR Mget(String self)
{
  return self->field;
}

static String Mset(String self, const string field)
{
  snprintf(Mget(self), STRING_SIZE, "%s", field);

  return self;
}

static Int Mto_i(String self)
{
  return string_to_i(Mget(self));
}

static String Minput(String self)
{
  {
    string_input(Mget(self));
  }

  return self;
}

static String Mprint(String self)
{
  {
    string_print(Mget(self));
  }

  return self;
}

String String_init(const string field)
{
  String new = (String) malloc(sizeof(String_t));
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const String_t tmp = {
      .delete = Mdelete,
      .getR   = MgetR,
      .get    = Mget,
      .set    = Mset,
      .to_i   = Mto_i,
      .input  = Minput,
      .print  = Mprint,
    };
    
    *new = tmp;
    Mset(new, field);
  }

  return new;
}

String String_new(void)
{
  return String_init(NULL);
}
