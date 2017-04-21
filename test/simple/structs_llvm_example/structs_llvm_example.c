struct RT {
  char A;
  int B[2][2];
  char C;
};
struct ST {
  int X;
  double Y;
  struct RT Z;
};

int main(){
	struct ST s[2];
	return s[1].Z.B[1][1];
}

