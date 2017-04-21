
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

  char x[100], y[100];
  int i,j,k;

int main() {
#ifdef KLEE
  klee_make_symbolic(&k, sizeof(k), "k");
#endif

  i = 0;
  while(x[i] != 0){
    y[i] = x[i];
    i++;
  }
  y[i] = 0;

  if(k >= 0 && k < i)
    if(y[k] != 0)
	    return 0;

  return 1;
}
