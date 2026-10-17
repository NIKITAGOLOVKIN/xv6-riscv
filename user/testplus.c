#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    int result = plus(2, 3);
    printf("result = %d\n", result);
    exit(0);
}