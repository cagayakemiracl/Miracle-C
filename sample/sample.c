/*
    整数の配列を作成し入力して出力するサンプルプログラム
*/

#include "../miracle.h"

void each_put(Int self)
{
  Put(self); putchar(' ');
}

int main(void)
{
  {
    New(Int, i); // Intクラスのインスタンス生成(要素数1)

    Set(i, 1)->add(i)->set_at(i, 1, 2)->print(i)->dealloc(i);
  }

  {
    ArrayNew(Int, i, 5); // 要素が５のIntクラスのインスタンス生成

    Fill(i, 3);
    {
      Int c = Dup(i); // iのコピー

      Fill(c, 9)->print(c)->dealloc(c);
    }
    Print(i)->dealloc(i);
  }

  /*
  {
    ArrayNew(Int, i, 3); // 要素が３のIntクラス生成

    Input(i)->each(i, each_put)->dealloc(i); putchar('\n');
  }
  */

  {
    ArrayNew(Int, i, 2);

    i->aquarion(i, 3);
    Fill(i, 5);
    Print(i);
    Dealloc(i);
  }

  return 0;
}
