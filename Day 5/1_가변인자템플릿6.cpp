#include <iostream>

// recursive

void foo() {}	// 재귀 종료

// 1. 첫 번째 인자는 독립된 변수 사용
template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()	=> 이 경우를 위해 인자없는 함수 필요
}

int main()
{
	foo(1, 3.4, 'A');
}





