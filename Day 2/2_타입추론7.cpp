// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	decltype(p)		d1; 

	// 규칙 #2. id-expression 이 아닌 경우
	// expression 이 등호의 왼쪽에 올 수 있으면 (lvalue) : 참조 타입
	// expression 이 등호의 왼쪽에 올 수 없으면 (rvalue) : 값 타입

	decltype(*p)	d2; // *p = 5   가능, 따라서 int&
	decltype(x[0])	d3; // x[0] = 5 가능, 따라서 int&

	decltype(n) d;		// id-expression이므로 규칙 1 적용, int
					
	decltype(n + n) d4;	// n+n = 5 불가능, 따라서 int 
	decltype(++n)   d5; // ++n = 5   가능, 따라서 int&
	decltype(n++)   d6; // n++ = 5 불가능, 따라서 int
			
}

++n; // operator++(n)
n++; // operator++(n, int)

int& operator++(int& a)
{
	a = a + 1;
	return a;
}

int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}