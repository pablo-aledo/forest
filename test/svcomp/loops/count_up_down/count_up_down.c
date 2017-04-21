
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main()
{
  unsigned int n;


#ifdef KLEE
  klee_make_symbolic(&n, sizeof(n), "n");
#endif

  if (n < 0 || n > 10) return 0;

  unsigned int x=n, y=0;
  while(x>0)
  {
    x--;
    y++;
  }
  if(y!=n) return 0;
  else return 1;
}
