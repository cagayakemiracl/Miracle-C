#include "Sstd.h"

String int_to_s(const int num)
{
  string str;
  
  snprintf(str, STRING_SIZE, "%d", num);
  
  return String_init(str);
}

void int_input(intR num) // 入力した整数をnumに格納
{
  string s; // 入力した文字列を格納 string

  string_input(s);
  *num = 0;
  sscanf(s, "%d", num);
}

void int_print(const int num)
{
  printf("%d", num);
}
