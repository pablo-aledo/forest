
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

main()
{
  int x;
  int y;
  int z;


#ifdef KLEE
  klee_make_symbolic(&x, sizeof(x), "x");
  klee_make_symbolic(&y, sizeof(y), "y");
  klee_make_symbolic(&z, sizeof(z), "z");
#endif


  while(x<100 && 100<z)
  {
    bool tmp;


#ifdef KLEE
  klee_make_symbolic(&tmp, sizeof(tmp), "tmp");
#endif

    if (tmp)
   {
     x++;
   }
   else
   {
     x--;
     z--;
   }
  }

  return 0;
}
