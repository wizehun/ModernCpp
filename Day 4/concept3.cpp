#include <iostream>
#include <vector>
#include <type_traits>
#include <concepts>
#include <algorithm>

// C++98 시절에는 아래 2개를 구별할 방법이 없었습니다.

template<typename IT, typename V>
void find(IT first, IT last, const V& value)
{
	std::cout << "값 검색\n";
}

template<typename IT, typename F>
void find(IT first, IT last, F f)
{
	std::cout << "조건 검색\n";
}

// C++20 부터는 템플릿 인자가 제약조건을 만족할때만 사용하게 하면 됩니다.

template<typename IT, typename V>
	requires (!std::predicate<V, typename IT::value_type>)
void xfind(IT first, IT last, const V& value)
{
	std::cout << "값 검색\n";
}

template<typename IT, typename F> 
	requires std::predicate<F, typename IT::value_type>
void xfind(IT first, IT last, F f)
{
	std::cout << "조건 검색\n";
}

// predicate<F, I> : F가 I 타입을 인자로 받아서 호출할 수 있어야 하고,
//					 반환타입이 bool 로 변환될수 있어야 한다는 concept

int main()
{
	std::vector<int> v = { 1,2,3 };

	xfind(v.begin(), v.end(), 3);
	xfind(v.begin(), v.end(), [](int n) {return n % 2 == 0; });

}