struct Struct3 {
	int int4;
	int int5;
};

struct Struct {
	double int1;
	int int2;
	struct Struct3 struct3;
};

int main(){
	struct Struct a;
	int b = a.int1 + a.int2 + a.struct3.int5;
}
