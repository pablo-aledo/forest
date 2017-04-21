

#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main() {
  int i, j=10, n, sn=0;

#ifdef KLEE
  klee_make_symbolic(&n, sizeof(n), "n");
#endif

  for(i=1; i<=n; i++) {
    if (i<j)
    sn = sn + (2);
    j--;
  }
  if(sn==n*(2) || sn == 0) return 1;
  else return 0;
}
