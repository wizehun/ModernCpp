#include "tuple.h"
#include <iostream>


// �ᱹ �κ� Ư��ȭ ������ ����ϰ�(N==0, N!= 0) 
// primary template �� ������ �ʽ��ϴ�.
// ���� ������ �˴ϴ�.
template<int N, typename T>
struct tuple_element;

template<typename T, typename ... Ts>
struct tuple_element<0, tuple<T, Ts...> >
{
	using type = T;						// 0��° ���Ÿ��
	using tupleType = tuple<T, Ts...>;	// 0��° ��Ҹ� �����ϴ� tuple Ÿ��
};

template<int N, typename T, typename ... Ts>
struct tuple_element<N, tuple<T, Ts...> >
{
	using type = typename tuple_element<N - 1, tuple<Ts...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Ts...>>::tupleType;
};

template<int N, typename TP>
typename tuple_element<N, TP>::type&
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');

	get<0>(t3) = 10;

	std::cout << get<0>(t3) << std::endl; // 10
	std::cout << get<1>(t3) << std::endl; // 3.4
	std::cout << get<2>(t3) << std::endl; // 'A'
}