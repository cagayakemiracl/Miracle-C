#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num); // int型変数をStringクラスのインスタンスに変換

// Intクラスの定義
typedef struct _Int {
  Int prev; // 双方向リスト
  Int next;
  Int self; // Intクラスの実体を指す
  
  int field; // int型のインスタンス変数
  
  void (Method delete)(Int self);              // インスタンスを削除
  intR (Method getR)(Int self);                // self->fieldのポインタを返す
  int (Method get)(Int self);                  // self->fieldの値を返す
  Int (Method set)(Int self, const int field); // self->fieldをfieldに変更
  Int (Method dup)(Int self);                  // selfをコピー
  String (Method to_s)(Int self);              // Stringクラスのインスタンスに変換
  Int (Method input)(Int self);                // 入力
  Int (Method print)(Int self);                // 出力
  
  Int (Method first)(Int self);                  // 配列の先頭の要素を返す
  Int (Method last)(Int self);                   // 配列の最後の要素を返す
  Int (Method element)(Int self, const int num); // 配列のnum番目の要素を返す
  Int (Method size)(Int self);                   // 配列の大きさを返す

  // 要素indexに対するメソッド
  intR (Method getRI)(Int self, const int index);                // self->fieldのポインタを返す
  int (Method getI)(Int self, const int index);                  // self->fieldnの値を返す
  Int (Method setI)(Int self, const int index, const int field); // self->fieldをfieldに変更
  String (Method to_sI)(Int self, const int index);              // Stringクラスのインスタンスに変換
  Int (Method inputI)(Int self, const int index);                // 入力
  Int (Method printI)(Int self, const int index);                // 出力

  Int (Method senseHart)(Int self, Int add); // うお〜〜！！燃える〜！！！
  Int (Method push)(Int self);   // 末尾に要素を追加
  
  // (配列の全要素)に反映するメソッド
  Int (Method fill)(Int self, const int field);  // self->fieldをfieldで初期化
  Int (Method inputA)(Int self); // 入力
  Int (Method printA)(Int self); // 出力
  
  Int (Method each)(Int self, void (Method func)(Int self));
  Int (Method eachI)(Int self, void (Method func)(Int self, Int index));
} Int_t;

#endif
