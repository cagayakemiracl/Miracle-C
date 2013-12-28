/*
  入力した整数をStringクラスのインスタンスに変換して表示するサンプルプログラム
*/

#include "../miracle.h"

int main(void)
{
  {
    New(Int, i);

    Push(i);
    Set(i, 0, 1);
    Set(i, 1, 2);
    Print(i)->delete(i); putchar('\n');
  }
  
  {
    New(Int, i);

    Push(i);
    Input(i)->print(i)->delete(i); putchar('\n');
  }
  
  return 0;
}
