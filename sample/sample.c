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

  {
    ArrayNew(Int, i, 2);

    i->aquarion(i, 3)->aquarion(i, 5)->fill(i, 7)->print(i);
    Int p = Dup(i); Dealloc(i);
    Fill(p, 2)->print(p)->dealloc(p);
  }
    
  {
    ArrayNew(Int, i, 3); // 要素が３のIntクラス生成

    i->aquarion(i, 2)->input(i)->each(i, each_put)->dealloc(i); putchar('\n');
  }

  return 0;
}
