

#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define SIZE 5

main()
{
  unsigned int j,k;
  int array[SIZE], menor;
  

#ifdef KLEE
  klee_make_symbolic(&array, sizeof(array), "array");
#endif


  for(j=0;j<SIZE;j++) {
       
       if(array[j]<=menor)
          menor = array[j];                          
    }                       
    
    if(array[0]>menor)
	    return 0;
    else
	    return 1;
}

