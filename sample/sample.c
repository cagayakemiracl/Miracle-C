/*
  入力した整数をStringクラスのインスタンスに変換して表示するサンプルプログラム
*/

#include "../miracle.h"

int main(void)
{
  New(Int, i); // Intクラスのインスタンスを定義
  
  String s = Input(i)->to_s(i); // Intクラスのインスタンスを変換したものをStringクラスのインスタンスとして定義
  Delete(i);
  Print(s)->delete(s); putchar('\n');
  
  return 0;
}
