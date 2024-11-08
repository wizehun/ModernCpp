#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args 의 모든 요소를 화면에 출력하고 싶다.
	printv(args...);	// printv(e1, e2, e3) 인데, printv 인자는 1개
						// error.
	printv(args)...;	// printv(e1), printv(e2), printv(e3) 의도
						// 하지만 error.

	// pack expansion 은 아래의 위치에서만 가능합니다.
	// 1. 함수 인자 () 안에서	goo(args...)
	// 2. {}, () 초기화 구문	int x[] = {args...}, Point pt(args...)
	// 3. 템플릿 인자			std::tuple<Ts...>

	// 억지로 끼워맞추기 (C++11 초창기)
	int dummy[] = { 0, (printv(args), 0)... }; // 이렇게 쓰면 모든 요소 출력
}


int main()
{
	foo(1, 2, 3);
}

