#include "miracle.h"

int main(void)
{
  New(Int, i);
  
  String s = Input(i)->to_s(i);
  Delete(i);
  Print(s)->delete(s);
  
  return 0;
}
