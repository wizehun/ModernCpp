#include <iostream>
#include <vector>
#include <type_traits>
#include <concepts>
#include <algorithm>

// C++98 �������� �Ʒ� 2���� ������ ����� �������ϴ�.

template<typename IT, typename V>
void find(IT first, IT last, const V& value)
{
	std::cout << "�� �˻�\n";
}

template<typename IT, typename F>
void find(IT first, IT last, F f)
{
	std::cout << "���� �˻�\n";
}

// C++20 ���ʹ� ���ø� ���ڰ� ���������� �����Ҷ��� ����ϰ� �ϸ� �˴ϴ�.

template<typename IT, typename V>
	requires (!std::predicate<V, typename IT::value_type>)
void xfind(IT first, IT last, const V& value)
{
	std::cout << "�� �˻�\n";
}

template<typename IT, typename F> 
	requires std::predicate<F, typename IT::value_type>
void xfind(IT first, IT last, F f)
{
	std::cout << "���� �˻�\n";
}

// predicate<F, I> : F�� I Ÿ���� ���ڷ� �޾Ƽ� ȣ���� �� �־�� �ϰ�,
//					 ��ȯŸ���� bool �� ��ȯ�ɼ� �־�� �Ѵٴ� concept

int main()
{
	std::vector<int> v = { 1,2,3 };

	xfind(v.begin(), v.end(), 3);
	xfind(v.begin(), v.end(), [](int n) {return n % 2 == 0; });

}