/*
  入力した整数をStringクラスのインスタンスに変換して表示するサンプルプログラム
*/

#include "../miracle.h"

int main(void)
{
  /*
  New(Int, i); // Intクラスのインスタンスを定義
  
  String s = Input(i)->to_s(i); // Intクラスのインスタンスを変換したものをStringクラスのインスタンスとして定義
  Delete(i);
  Print(s)->delete(s); putchar('\n');
  */
  New(IntList, l);

  l->add(l);
  l->field->set(l->field, 1);
  l->next->field->set(l->next->field, 2);
  l->field->print(l->field); putchar('\n');
  l->next->field->print(l->next->field); putchar('\n');
  
  return 0;
}
