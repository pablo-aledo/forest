
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

long gcd_test(long a, long b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (a == 0) {
        return b;
    }

    while (b != 0) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}


int main()
{
    long x;
    long y;
    long g;


#ifdef KLEE
    klee_make_symbolic(&x, sizeof(x), "x");
    klee_make_symbolic(&y, sizeof(y), "y");
#endif

	if(x < 10 && y < 10 && x > 0 && y > 0)
    g = gcd_test(x, y);

    return 0;
}
