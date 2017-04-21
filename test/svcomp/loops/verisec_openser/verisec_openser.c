
#ifdef KLEE 
#include "/llvm-2.9/klee/include/klee/klee.h"
#endif 

char *r_strncpy(char *dst, const char *src, int n)
{
int i;
char *temp;
temp = dst; 
for (i = 0; i < n; i++)
*dst++ = *src++;
return temp;
}

typedef int NSS_STATUS;
typedef char fstring[2];
struct sockaddr_un
{
  char sun_path[2 + 1];
};
static int parse_expression_list(char *str)
{
  int start=0, i=-1, j=-1;
  char str2[2];
  if (!str) return -1;
  do {
    i++;
    switch(str[i]) {
    case 0:
      while ((str[start] == ' ') || (str[start] == '\t')) start++;
      if (str[start] == '"') start++;
      j = i-1;
      while ((0 < j) && ((str[j] == ' ') || (str[j] == '\t'))) j--;
      if ((0 < j) && (str[j] == '"')) j--;
      if (start<=j) {
        r_strncpy(str2, str+start, j-start+1);
        if(!(j - start + 1 < 2)) return 0;
        str2[j-start+1] = 0;
      } else {
        return -1;
      }
      start = i+1;
    }
  } while (str[i] != 0);
  return 0;
}
int main ()
{
  char A [2 + 2 + 4 +1];
  A[2 + 2 + 4] = 0;
  parse_expression_list (A);
  return 0;
}
