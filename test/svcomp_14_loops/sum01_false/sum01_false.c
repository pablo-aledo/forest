void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: goto ERROR;
  }
  return;
}
#define a (2)
extern unsigned int __VERIFIER_nondet_uint();
int main() { 
  int i, n=__VERIFIER_nondet_uint(), sn=0;
  for(i=1; i<=n; i++) {
    if (i<10)
    sn = sn + a;
  }
  __VERIFIER_assert(sn==n*a || sn == 0);
}
