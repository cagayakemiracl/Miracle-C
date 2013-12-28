#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num); // int型変数をStringクラスのインスタンスに変換

// Intクラスの定義
typedef struct _Int {
  Int prev;
  Int next;
  Int self;
  
  int field; // int型のインスタンス変数
  
  void (Method delete)(Int self);              // インスタンスを削除
  intR (Method getR)(Int self, const int index);                // self->fieldのポインタを返す
  int (Method get)(Int self, const int index);                  // self->fieldの値を返す
  Int (Method set)(Int self, const int index, const int field); // self->fieldをfieldに変更
  Int (Method first)(Int self); // 配列の先頭の要素を返す
  Int (Method last)(Int self); // 配列の最後の要素を返す
  Int (Method select)(Int self, const int num); // 配列のnum番目の要素を返す
  Int (Method size)(Int self); // 配列の大きさを返す
  String (Method to_s)(Int self, const int index);              // Stringクラスのインスタンスに変換
  Int (Method input)(Int self);                // 入力関数
  Int (Method print)(Int self);                // 出力関数
  Int (Method push)(Int self); // 末尾に要素を追加
} Int_t;

#endif
