
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main()
{
  unsigned int x1, x2, x3;
  int c1, c2;

#ifdef KLEE
  klee_make_symbolic(&x1, sizeof(x1), "x1");
  klee_make_symbolic(&x2, sizeof(x2), "x2");
  klee_make_symbolic(&x3, sizeof(x3), "x3");
  klee_make_symbolic(&c1, sizeof(c1), "c1");
  klee_make_symbolic(&c2, sizeof(c2), "c2");
#endif


  unsigned int d1=1, d2=1, d3=1;

  while(x1>0 && x2>0 && x3>0)
  {
    if (c1) x1=x1-d1;
    else if (c2) x2=x2-d2;
    else x3=x3-d3;

#ifdef KLEE
  klee_make_symbolic(&c1, sizeof(c1), "c1");
  klee_make_symbolic(&c2, sizeof(c2), "c2");
#endif

  }

  if(x1==0 && x2==0 && x3==0) return 1;
  else return 0;
}
