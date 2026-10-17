#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: plus <a> <b>\n");
        exit(1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int result = plus(a, b);

    printf("%d\n", result);
    exit(0);
}
