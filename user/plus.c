#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, int brgc)
{
  plus(argc, brgc);
  exit(0);
}
