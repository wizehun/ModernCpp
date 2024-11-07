#include <iostream>
#include <type_traits>

// C++11 enable_if ���
/*
template<typename T>
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << std::endl;
}
*/
// C++20 �� requires clauses ��� ����.
// enable_if ��� ��ũ���� "�������� �����!"
// => java, c# �� generic constraint ����� ����.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}