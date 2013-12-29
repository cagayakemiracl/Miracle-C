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
    New(Int, i); // Intクラスのインスタンス生成(要素数1)
    
    Set(i, 1);
    Push(i);
    SetI(i, 1, 2);
    PrintA(i)->delete(i);
  }

  {
    ArrayNew(Int, i, 5); // 要素が５のIntクラスのインスタンス生成
    
    Fill(i, 3);
    { 
      Int c = i->dup(i); // iのコピー
      
      Fill(c, 9)->printA(c)->delete(c);
    }
    PrintA(i)->delete(i);
  }

  {
    ArrayNew(Int, i, 3); // 要素が３のIntクラス生成

    InputA(i)->each(i, each_print)->delete(i); putchar('\n');
  }
  
  return 0;
}
