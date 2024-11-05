#include <iostream>

//int main()
//{
//	int x[3] = { 1, 2, 3 };
//
//	int* p1 = x;		// 배열의 첫 번째 요소의 주소를 담는다.
//	int(*p2)[3] = &x;	// 배열 자체의 주소를 담는다.
//
//	// 첫 번째 요소를 수정할 때
//	*p1 = 10;
//	(*p2)[0] = 10;
//}


int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4);	// auto : int
							// 우변에서 reference 제거 후 결정

	// decltype(함수호출식) : 함수호출결과로 나오는 (리턴) 타입 조사
	//						 실제 함수가 호출되는 것은 아님. 선언문으로 조사.
	decltype(foo(1, 3.4)) ret2 = foo(1, 3.4);

	// C++14 : decltype(auto) 도입
	// => auto 자리에 우변을 넣어 달라
	// => 또는, 우변으로 추론하는데 decltype 규칙으로
	decltype(auto) ret2 = foo(1, 3.4);
}