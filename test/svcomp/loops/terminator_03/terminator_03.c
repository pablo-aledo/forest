
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 


main()
{
  int x;
  int y;


#ifdef KLEE
  klee_make_symbolic(&x, sizeof(x), "x");
  klee_make_symbolic(&y, sizeof(y), "y");
#endif

  if (y>0)
  {
    while(x<100)
    {
      x=x+y;
     }
  }
  if(y<=0 || (y<0 && x>=100)) return 0;
  else return 1;
}
