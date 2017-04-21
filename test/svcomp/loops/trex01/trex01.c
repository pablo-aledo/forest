
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

void f(int d) {
  int x, y, k, z = 1;
  L1:
  while (z < k) { z = 2 * z; }
  if(!(z>=2)) return 0;
  L2:
  while (x > 0 && y > 0) {
    bool c;

#ifdef KLEE
  klee_make_symbolic(&c, sizeof(c), "c");
#endif

    if (c) {
      P1:
      x = x - d;
      y = __VERIFIER_nondet_bool();
      z = z - 1;
    } else {
      y = y - d;
    }
  }
}

void main() {
  bool c;

#ifdef KLEE
  klee_make_symbolic(&c, sizeof(c), "c");
#endif

  if (c) {
    f(1);
  } else {
    f(2);
  }
}
