
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int x;

void foo() {
  x--;
}

int main() {

#ifdef KLEE
  klee_make_symbolic(&x, sizeof(x), "x");
#endif


  while (x > 0) {
    bool c;

#ifdef KLEE
  klee_make_symbolic(&c, sizeof(c), "c");
#endif

    if(c) foo();
    else foo();
  }
  if(x==0) return 0;
  else return 1;
}
