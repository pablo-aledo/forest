
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

void foo()
{
  int y=0;
  int c1, c2;

#ifdef KLEE
  klee_make_symbolic(&c1, sizeof(c1), "c1");
  klee_make_symbolic(&c2, sizeof(c2), "c2");
#endif

  if (c1) y++;
  if (c2) y--;
  else y+=10;
}

int main()
{
  int d = 1;
  int x;
  int c1, c2;

#ifdef KLEE
  klee_make_symbolic(&c1, sizeof(c1), "c1");
  klee_make_symbolic(&c2, sizeof(c2), "c2");
#endif

  if (c1) d = d - 1;
  if (c2) foo();

#ifdef KLEE
  klee_make_symbolic(&c1, sizeof(c1), "c1");
  klee_make_symbolic(&c2, sizeof(c2), "c2");
#endif

  if (c1) foo();
  if (c2) d = d - 1;

  while(x>0)
  {
    x=x-d;
  }

  if(x<=0) return 0;
  else return 1;
}
