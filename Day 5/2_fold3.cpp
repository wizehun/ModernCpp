#include <vector>
#include <iostream>

template<typename ... Ts>
void foo(std::vector<int>& v, Ts...args)
{
	// args 의 모든 요소를 v에 넣어 보세요(push_back)
	( v.push_back(args), ... );
}

int main()
{
	std::vector<int> v;

	foo(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}