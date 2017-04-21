
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define N_LIN 10
#define N_COL 10

int main()
{


  unsigned int j,k;
  int matriz[N_COL][N_LIN], maior;

#ifdef KLEE
  klee_make_symbolic(&maior, sizeof(maior), "maior");
  klee_make_symbolic(&matriz, sizeof(matriz), "matriz");
#endif


  for(j=0;j<N_COL;j++)
    for(k=0;k<N_LIN;k++)
    {

       if(matriz[j][k]>maior)
          maior = matriz[j][k];
    }

  for(j=0;j<N_COL;j++)
    for(k=0;k<N_LIN;k++)
      if(!(matriz[j][k]<maior)) return 1;


  return 0;
}
