﻿// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// decltype(expression)
	// 규칙 #1. expression 이 심볼의 이름일때 (id-expression)
	// => 해당 심볼의 선언을 보고 결정
	decltype(n) d1;		// int d1; 
	decltype(r) d2;		// int& d2;		   초기값이 없기 때문에 error
	decltype(c) d3;		// const int d3;   초기값이 없기 때문에 error
	decltype(p) d4;		// int* d4;

}
