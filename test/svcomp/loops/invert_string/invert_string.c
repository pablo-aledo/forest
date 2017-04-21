
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

#define MAX 10
int main() {


    char str1[MAX], str2[MAX];
    int cont, i, j;
    cont = 0;


#ifdef KLEE
  klee_make_symbolic(&str1, sizeof(str1), "str1");
#endif

 str1[MAX-1]= '\0';

    j = 0;

    for (i = MAX - 1; i >= 0; i--) {
        str2[j] = str1[0];
        j++;
    }

    j = MAX-1;
    for (i=0; i<MAX; i++) {
      if(str1[i] == str2[j]) return 0;
   j--;
    }

    return 1;
}
