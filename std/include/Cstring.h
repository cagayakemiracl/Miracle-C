#ifndef _C_STRING_H_INCLUDED_
#define _C_STRING_H_INCLUDED_

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
