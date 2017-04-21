
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 


int main() { 
  unsigned int i, n, sn=0;

#ifdef KLEE
    klee_make_symbolic(&n, sizeof(n), "n");
#endif

  for(i=0; i<=n; i++) {
    sn = sn + i;
  }
}
