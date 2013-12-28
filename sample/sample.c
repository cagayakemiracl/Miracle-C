/*
  整数の配列を作成し入力して出力するサンプルプログラム
*/

#include "../miracle.h"

void each_print(Int self)
{
  Print(self); putchar(' ');
}

int main(void)
{
  {
    New(Int, i);
    
    Set(i, 1);
    Push(i);
    SetI(i, 1, 2);
    PrintA(i)->delete(i);
  }
  
  {
    ArrayNew(Int, i, 3);

    InputA(i)->each(i, each_print)->delete(i); putchar('\n');
  }
  
  return 0;
}
