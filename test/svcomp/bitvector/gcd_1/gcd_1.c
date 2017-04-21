
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 


signed char gcd_test(signed char a, signed char b)
{
    signed char t;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int main()
{
    signed char x;
    signed char y;
    signed char g;


#ifdef KLEE
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");
#endif



    if (y > 0 && x % y == 0) {
        g = gcd_test(x, y);
    }

    return 0;
}
