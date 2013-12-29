#ifndef _STRING_H_INCLUDED_
#define _STRING_H_INCLUDED_

Int string_to_i(const string str); // string型をIntクラスのインスタンスに変換
void string_get(charR str);        // string型の標準入力関数

// Stringクラスの定義
typedef struct _String {
  string field; // string型のインスタンス変数
  
  void (Method dealloc)(String self);                   // インスタンスを削除
  String (Method set)(String self, const string field); // self->fieldをfieldに値を変更
  Int (Method to_i)(String self);                       // Intクラスのインスタンスに変換
  String (Method get)(String self);                     // 入力関数
  String (Method put)(String self);                     // 出力関数
} String_t;

#endif
