// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 인자 1개만 넣을 수 있는 함수
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f(std::forward<T>(arg));
}

// 인자의 개수 제한 없는 함수
template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return f(std::forward<Ts>(args)...);
			// f(std::forward<T1>(e1), std::forward<T2>(e2), std::forward<T3>(e3));
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

