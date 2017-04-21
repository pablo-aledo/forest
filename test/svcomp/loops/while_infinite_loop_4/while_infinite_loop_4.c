
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int x=0;

void eval(void)
{
  while (1) {
      x=1;
      break;
  }
  return;
}


int main() {

  while(1)
  {
    eval();
    if(!(x==0)) return 0;
  }

  if(x==0) return 0;
  else return 0;
}
