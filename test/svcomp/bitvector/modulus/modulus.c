
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 


int main()
{
    unsigned int n;
    unsigned int s;


#ifdef KLEE
    klee_make_symbolic(&n, sizeof(n), "n");
    klee_make_symbolic(&s, sizeof(s), "s");
#endif

    unsigned int d;
    unsigned int m;
    d = (1 << s) - 1;
    if (d > 0) {
        m = n;
        while (n > d) {
            m = 0;
            while (n > 0) {
                m += n & d;
                n = n >> s;
            }
            n = m;
        }
        if (m == d) {
            m = 0;
        }
    }
    return 0;
}
