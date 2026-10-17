#include "types.h"
#include "riscv.h"
#include "defs.h"



uint64 sys_plus(void){
    int a, b;
    
    argint(0, &a);
    argint(2, &b);

    printk("sys_plus    " "%d   a - %d,  b- %d\n", a+ b, a, b);

    return a + b;

}