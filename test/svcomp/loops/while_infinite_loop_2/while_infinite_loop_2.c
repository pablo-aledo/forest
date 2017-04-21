

#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main() {
  int x=0;

  while(1)
  {
    if(!(x==0)) return 0;
  }

  if(x==0) return 0;
  else return 1;
}
