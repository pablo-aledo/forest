
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main()
{
  int x;


#ifdef KLEE
  klee_make_symbolic(&x, sizeof(x), "x");
#endif

  int *p = &x;

  while(x<100) {
   (*p)++;
  }
  return 0;
}
