// reference collapsing - 91 page

// 사전 지식

int main()
{
	int n = 10;

	int *p = &n;
	int* *pp = &p;	// ok. 포인터의 포인터는 가능하다.

	int& r = n;
	int& &rr = r;	// error. 레퍼런스의 레퍼런스를
					//		  "직접 코드로 작성" 할 수 없다.

	// 그런데, 타입추론이나 alias (별칭) 사용 시 발생하는
	// reference의 reference는 에러가 아니다.
	// "reference collapsing" 규칙 사용
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n ;	// int& &		=> int&
	RREF& r4 = n ;	// int&& &		=> int&
	LREF&& r5 = n;	// int& &&		=> int&
	RREF&& r6 = 3;	// int&& &&		=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a;
				// => int& r = a;
}





