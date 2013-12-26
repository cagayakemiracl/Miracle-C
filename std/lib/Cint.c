#include "Sstd.h"

static void Mdelete(Int self)
{
  free(self);
}

static intR MgetR(Int self)
{
  return &(self->field);
}

static int Mget(Int self)
{
  return self->field;
}

static Int Mset(Int self, const int field)
{
  {
    *MgetR(self) = field;
  }
  
  return self;
}

static String Mto_s(Int self)
{
  return int_to_s(Mget(self));
}

static Int Minput(Int self)
{
  {
    int_input(MgetR(self));
  }

  return self;
}

static Int Mprint(Int self)
{
  {
    int_print(Mget(self));
  }

  return self;
}

Int Int_init(const int field)
{
  Int new = (Int) malloc(sizeof(Int_t));
  if (!new) {
    exit(EXIT_FAILURE);
  } else {
    const Int_t tmp = {
      .delete = Mdelete,
      .getR = MgetR,
      .get = Mget,
      .set = Mset,
      .to_s = Mto_s,
      .input = Minput,
      .print = Mprint,
    };

    *new = tmp;
    Mset(new, field);
  }

  return new;
}

Int Int_new(void)
{
  return Int_init(0);
}
