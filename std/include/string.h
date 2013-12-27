#ifndef _STRING_H_INCLUDED_
#define _STRING_H_INCLUDED_

Int string_to_i(const string str);
void string_input(charR str); // string型の標準入力関数

typedef struct _String {
  string field;
  void (Method delete)(String self);
  stringR (Method getR)(String self);
  charR (Method get)(String self);
  String (Method set)(String self, const string field);
  Int (Method to_i)(String self);
  String (Method input)(String self);
  String (Method print)(String self);
} String_t;

#endif
