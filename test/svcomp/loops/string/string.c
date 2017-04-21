
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define MAX 5


main()
{
  char string_A[MAX], string_B[MAX];
  int i, j, nc_A, nc_B, found=0;  


#ifdef KLEE
  klee_make_symbolic(&string_A, sizeof(string_A), "string_A");
  klee_make_symbolic(&string_B, sizeof(string_B), "string_B");
#endif
  
  if(!(string_A[MAX-1]=='\0')) return 0;
  if(!(string_B[MAX-1]=='\0')) return 0;

  nc_A = 0;
  while(string_A[nc_A]!='\0')
    nc_A++;

  nc_B = 0;
  while(string_B[nc_B]!='\0')
    nc_B++;

  if(!(nc_B >= nc_A)) return 0;
  
  
  i=j=0;
  while((i<nc_A) && (j<nc_B))
  {
    if(string_A[i] == string_B[j]) 
    {
       i++;
       j++;
    }   
    else
    {
       i = i-j+1;
       j = 0;
    }   
  } 

  found = (j>nc_B-1);
  
  if(found == 0 || found == 1) return 0;
  else return 1;
}

