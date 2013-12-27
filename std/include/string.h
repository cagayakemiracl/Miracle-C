#ifndef _STRING_H_INCLUDED_
#define _STRING_H_INCLUDED_

Int string_to_i(const string str); // string型をIntクラスのインスタンスに変換
void string_input(charR str);      // string型の標準入力関数

// Stringクラスの定義
typedef struct _String {
  string field; // string型のインスタンス変数
  
  void (Method delete)(String self);                    // インスタンスを削除
  stringR (Method getR)(String self);                   // self->fieldのポインタを返す 
  charR (Method get)(String self);                      // self->fieldの値を返す
  String (Method set)(String self, const string field); // self->fieldをfieldに値を変更
  Int (Method to_i)(String self);                       // Intクラスのインスタンスに変換
  String (Method input)(String self);                   // 入力関数
  String (Method print)(String self);                   // 出力関数
} String_t;

#endif
