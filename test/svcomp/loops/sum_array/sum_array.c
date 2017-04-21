
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define M 10

int main()
{
  int A[M], B[M], C[M];

#ifdef KLEE
  klee_make_symbolic(&A, sizeof(A), "A");
  klee_make_symbolic(&B, sizeof(B), "B");
#endif

  unsigned int i;

  for(i=0;i<M;i++)
     C[i]=A[i]+B[i];

  for(i=0;i<M;i++)
     if(!(C[i]==A[i]-B[i])) return 0;

  return 1;
}
