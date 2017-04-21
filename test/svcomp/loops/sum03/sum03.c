
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main() {
  int sn=0;
  unsigned int loop1, n1;

#ifdef KLEE
  klee_make_symbolic(&loop1, sizeof(loop1), "loop1");
  klee_make_symbolic(&n1, sizeof(n1), "n1");
#endif


  unsigned int x=0;

  while(1){
    if (x<10)
      sn = sn + (2);
    x++;
    if(!(sn==x*(2) || sn == 0))
	    return 0;
  }
}
