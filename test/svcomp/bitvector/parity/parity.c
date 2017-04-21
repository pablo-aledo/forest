
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main()
{
    unsigned int v;

#ifdef KLEE
    klee_make_symbolic(&v, sizeof(v), "v");
#endif

    unsigned int v1;
    unsigned int v2;
    char parity1;
    char parity2;
    v1 = v;
    parity1 = (char)0;
    while (v1 != 0) {
        if (parity1 == (char)0) {
            parity1 = (char)1;
        } else {
            parity1 = (char)0;
        }
        v1 = v1 & (v1 - 1U);
    }
    v2 = v;
    parity2 = (char)0;
    v2 = v2 ^ (v2 >> 1u);
    v2 = v2 ^ (v2 >> 2u);
    v2 = (v2 & 286331153U) * 286331153U;
    if (((v2 >> 28u) & 1u) == 0) {
        parity2 = (char)0;
    } else {
        parity2 = (char)1;
    }
    return 0;
}

