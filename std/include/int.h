#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num); // int型変数をStringクラスのインスタンスに変換

// Intクラスの定義
typedef struct _Int {
  Int prev; // 双方向リスト
  Int next;
  Int child; // Intクラスの実体を指す 多次元配列を実現するために使う
  
  int field; // int型のインスタンス変数

  // 要素が一つのインスタンスに対するメソッド
  Int (Method set)(Int self, const int field); // self->fieldをfieldに変更
  String (Method to_s)(Int self);              // Stringクラスのインスタンスに変換
  Int (Method get)(Int self);                  // 入力
  Int (Method put)(Int self);                  // 出力

  // 配列に対するメソッド
  Int (Method first)(Int self);               // 配列の先頭の要素を返す
  Int (Method last)(Int self);                // 配列の最後の要素を返す
  Int (Method at)(Int self, const int index); // 配列のnum番目の要素を返す
  Int (Method size)(Int self);                // 配列の大きさを返す

  // 要素indexの一つのインスタンスに対するメソッド
  Int (Method set_at)(Int self, const int field, const int index); // self->fieldをfieldに変更
  String (Method to_s_at)(Int self, const int index);              // Stringクラスのインスタンスに変換
  Int (Method get_at)(Int self, const int index);                  // 入力
  Int (Method put_at)(Int self, const int index);                  // 出力

  Int (Method concat)(Int self, Int node);          // selfの末尾にnodeをくっつける
  Int (Method push)(Int self, const int field);     // selfの末尾にインスタンスを初期値fieldでくっつける
  Int (Method add)(Int self);                       // selfの末尾に新しいインスタンスをくっつける
  Int (Method genesis)(Int self, Int node);         // selfとnodeをくっつける
  Int (Method unite)(Int self, Int node);           // selfの全要素にnodeを複製したものをくっつける
  Int (Method aquarion)(Int self, const int index); // selfの全要素に要素indexの新しいインスタンスをくっつける
  
  // 配列の全要素に反映するメソッド
  void (Method dealloc)(Int self);              // インスタンスを削除
  Int (Method fill)(Int self, const int field); // self->fieldをfieldで初期化
  Int (Method dup)(Int self);                   // selfをコピー
  Int (Method input)(Int self);                 // 入力
  Int (Method print)(Int self);                 // 出力

  // マクロの方が有能なのであまり使わない
  Int (Method each)(Int self, void (Method func)(Int self));             
  Int (Method eachWI)(Int self, void (Method func)(Int self, Int index));
} Int_t;

#endif
