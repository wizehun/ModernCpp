#include <iostream>

// 아래처럼 function overloading 가능
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	
	foo(n);		// n : lvalue
				// (1) int& 버전 호출 
				// (2) 없으면 const int& 버전 호출
	
	foo(10);	// 10 : rvalue
				// (1) int&& 버전 호출
				// (2) 없으면 const int& 버전 호출

	// lvalue, rvalue 를 한개의 함수에서 처리하려면?
	// => const lvalue reference 버전으로 만든다.

	// lvalue, rvalue 를 다르게 처리하려면?
	// => lvalue reference 와 rvalue reference 버전을 각각 만든다.
}







