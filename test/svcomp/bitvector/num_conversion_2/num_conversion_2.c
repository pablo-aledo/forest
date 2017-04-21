
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main()
{
    unsigned char x;


#ifdef KLEE
    klee_make_symbolic(&x, sizeof(x), "x");
#endif

    unsigned char y;
    unsigned char c;

    y = 0;
    c = 0;
    while (c < (unsigned char)8) {
        unsigned char i = ((unsigned char)1) << c;
        unsigned char bit = x & i;
        if (bit != (unsigned char)0) {
            y = y + i;
        }
        c = c + ((unsigned char)1);
    }

    return 0;
}
