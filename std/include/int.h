#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num); // int型変数をStringクラスのインスタンスに変換

// Intクラスの定義
typedef struct _Int {
  Int prev; // 双方向リスト
  Int next;
  Int self; // Intクラスの実体を指す
  
  int field; // int型のインスタンス変数

  // 要素が一つのインスタンスに対するメソッド
  void (Method delete)(Int self);              // インスタンスを削除
  intR (Method getR)(Int self);                // self->fieldのポインタを返す
  int (Method get)(Int self);                  // self->fieldの値を返す
  Int (Method set)(Int self, const int field); // self->fieldをfieldに変更
  String (Method to_s)(Int self);              // Stringクラスのインスタンスに変換
  Int (Method input)(Int self);                // 入力
  Int (Method print)(Int self);                // 出力

  // 配列に対するメソッド
  Int (Method first)(Int self);                  // 配列の先頭の要素を返す
  Int (Method last)(Int self);                   // 配列の最後の要素を返す
  Int (Method element)(Int self, const int num); // 配列のnum番目の要素を返す
  Int (Method dup)(Int self);                    // selfをコピー
  Int (Method size)(Int self);                   // 配列の大きさを返す

  // 要素indexの一つのインスタンスに対するメソッド
  intR (Method getRI)(Int self, const int index);                // self->fieldのポインタを返す
  int (Method getI)(Int self, const int index);                  // self->fieldnの値を返す
  Int (Method setI)(Int self, const int index, const int field); // self->fieldをfieldに変更
  String (Method to_sI)(Int self, const int index);              // Stringクラスのインスタンスに変換
  Int (Method inputI)(Int self, const int index);                // 入力
  Int (Method printI)(Int self, const int index);                // 出力

  // 貴女と合体したい
  Int (Method senseHart)(Int self, Int add); // うお〜〜！！燃える〜！！！
  Int (Method push)(Int self);               // ゼーロテュピアーグラディウス!
  
  // (配列の全要素)に反映するメソッド
  Int (Method fill)(Int self, const int field);  // self->fieldをfieldで初期化
  Int (Method inputA)(Int self);                 // 入力
  Int (Method printA)(Int self);                 // 出力

  // マクロスの方が有能なのであまり使わない
  Int (Method each)(Int self, void (Method func)(Int self));             // 行くぜ！可愛い子ちゃん！！ヒャホーーー！！
  Int (Method eachI)(Int self, void (Method func)(Int self, Int index)); // お前達が、俺の翼だ！
} Int_t;

#endif
