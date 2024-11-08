#include <iostream>

template<typename ... Types> void foo(Types ... args)
{
	// #1. parameter pack 용어 알아두세요
	// Ts	: int, int, int		<= template parameter pack
	// args	: 1, 2, 3			<= function parameter pack

	// #2.pack 안에 요소 개수 확인
	// => sizeof...(pack이름)
	std::cout << sizeof...(Ts) << std::endl;
	std::cout << sizeof...(args) << std::endl;

	// #3. pack 안에 있는 요소에 접근하는 방법
	// 1. pack expansion - C++11 가장 널리 사용하는 일반적인 기술
	// 2. recursive 유사코드 - C++11
	// 3. fold expression - C++17
	// 4. pack indexing - C++26

	// pack indexing 코드 (C++26)
	using T = Ts...[0];	 // int
	auto n = args...[0]; // 1
}

int main()
{
	foo(1, 2, 3);
}
