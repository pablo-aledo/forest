
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 


int main() {
  int i=0, x=0, y=0;
  int n;
  int assertion;


#ifdef KLEE
  klee_make_symbolic(&n, sizeof(n), "n");
#endif

  if( n < 0 ) return 0;

  for(i=0; i<n; i++)
  {
    x = x-y;

    if(x==0) assertion = 1;
    else assertion = 2;

#ifdef KLEE
  klee_make_symbolic(&y, sizeof(y), "y");
#endif

    if(y==0) return 0;

    x = x+y;

    if(x!=0) assertion = 3;
    else assertion = 4;
  }
  if(x==0) assertion = 5;
  else assertion = 6;
}

