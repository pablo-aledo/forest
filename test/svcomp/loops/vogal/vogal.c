
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

main(void)
{
  char string_entrada[10], vetor_vogais[]={'a','A','e','E','i','I','o','O','u','U','\0'};;
  unsigned int i,j,cont, tam_string, n_caracter;


#ifdef KLEE
  klee_make_symbolic(&string_entrada, sizeof(string_entrada), "string_entrada");
#endif


  string_entrada[10 -1]='\0';

  n_caracter = 0;
  while(string_entrada[n_caracter]!='\0')
    n_caracter++;

  cont = 0;
  for(i=0;i<n_caracter;i++)
     for(j=0;j<8;j++)
        if(string_entrada[i] == vetor_vogais[j])
           cont++;

  i=0;
  int cont_aux = 0;
  while(string_entrada[i]!='\0')
  {
    for(j=0;j<10;j++)
    {
        if(string_entrada[i] == vetor_vogais[j])
           cont_aux++;
    }
    i++;
  }
  if(cont_aux==cont) return 0;
  else return 1;
}
