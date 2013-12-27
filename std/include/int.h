#ifndef _INT_H_INCLUDED_
#define _INT_H_INCLUDED_

String int_to_s(const int num);

typedef struct _Int {
  int field;
  void (Method delete)(Int self);
  intR (Method getR)(Int self);
  int (Method get)(Int self);
  Int (Method set)(Int self, const int field);
  String (Method to_s)(Int self);
  Int (Method input)(Int self);
  Int (Method print)(Int self);
} Int_t;

#endif
