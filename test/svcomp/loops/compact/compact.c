
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

int main(int argc, char **argv)
{
	static char array[100];
	char ND;

#ifdef KLEE
  klee_make_symbolic(&ND, sizeof(ND), "ND");
#endif
	unsigned int i;

	for (i = 0; i < sizeof(array); i++)
		if (array[i] == ND)
			return i;

	goto ERROR;
ERROR:
	return 0;
}
