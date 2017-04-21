
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main (void)
{
  char in[11];
  char *s;
  unsigned char c;
  int i, j;
  int idx_in;

#ifdef KLEE
  klee_make_symbolic(&in, sizeof(in), "in");
#endif

  in[10] = 0;
  idx_in = 0;
  s = in;
  i = 0;
  c = in[idx_in];
  while (('0' <= c) && (c <= '9'))
  {
    j = c - '0';
    i = i * 10 + j;
    idx_in++;
    c = in[idx_in];
  }

  if(i >= 0) return 1;
  else return 0;
}
