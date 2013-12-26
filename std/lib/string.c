#include "Sstd.h"

Int string_to_i(const string str)
{
  int num;

  sscanf(str, "%d", &num);
  
  return Int_init(num);
}

charR string_input(charR str) // string型の標準入力関数
{
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

  return str;
}

charR string_print(const string str)
{
  {
    fputs(str, stdout);
  }

  return (charR) str;
}
