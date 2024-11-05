int main()
{
	int x[3] = { 1,2,3 };

	// auto 와 decltype 의 차이점 #1

	decltype(x[0]) d = x[0];	// int& d = x[0];
	auto a = x[0];				// int a = x[0];

	// 타입 추론과 배열 이름
	// x의 타입 : int[3]
	// => 타입 이름은 선언문에서 심볼의 이름만 제거하면 된다.
	// => main 함수의 타입은 int()
	
	decltype(x) d1;	// int d1[3]

	auto a1 = x;
	auto& a2 = x;
}

