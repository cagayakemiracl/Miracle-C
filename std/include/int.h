#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num); // int型変数をStringクラスのインスタンスに変換

// Intクラスの定義
typedef struct _Int {
  int field; // int型のインスタンス変数
  
  void (Method delete)(Int self);              // インスタンスを削除
  intR (Method getR)(Int self);                // self->fieldのポインタを返す
  int (Method get)(Int self);                  // self->fieldの値を返す
  Int (Method set)(Int self, const int field); // self->fieldをfieldに変更
  String (Method to_s)(Int self);              // Stringクラスのインスタンスに変換
  Int (Method input)(Int self);                // 入力関数
  Int (Method print)(Int self);                // 出力関数
} Int_t;

typedef struct _IntList {
  IntList next; // 双方向リスト
  IntList prev;
  Int field; // この配列の要素

  void (Method delete)(IntList self); // インスタンスを削除
  IntList (Method getTail)(IntList self); // 配列の最後の要素を返す
  IntList (Method select)(IntList self, const int num); // 配列のnum番目の要素を返す
  IntList (Method add)(IntList self); // 末尾に要素を追加
} IntList_t;

#endif
