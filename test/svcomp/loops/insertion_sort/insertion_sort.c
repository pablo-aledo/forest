

#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define SIZE 10


int main() {
   int i, j, k, key;
   int v[SIZE];

#ifdef KLEE
  klee_make_symbolic(&j, sizeof(j), "j");
#endif

   for (j=1;j<SIZE;j++) {
      key = v[j];
      i = j - 1;
      while((i>=0) && (v[i]>key)) {
         v[i+1] = v[i];
         i = i - 1;
      }
      v[i+1] = key;
  }
  for (k=1;k<SIZE;k++)
   if(v[k-1]<=v[k]) return 1;
   return 0;
}
