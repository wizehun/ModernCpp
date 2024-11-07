#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

template<typename T>
int foo(T a)
{
	typename T::type n; // SFINAE �� ����ɱ�� ?
	// ������ ���ñ�� ?
	// => ����
	return 0;
}
// SFINAE �� �Լ��� signature �� ���� �Ҷ��� ����˴ϴ�.
// => ��ȯ Ÿ�� ��ġ
// => �Լ� ���� ��ġ
// => ���ø� ���� ��ġ

template<typename T>
typename T::type foo(T a) { return 0; }

template<typename T>
int foo(T a, typename T::type b = 0) { return 0; }

template<typename T, typename T2 = typename T::type >
int foo(T a) { return 0; }

int main()
{
	foo(3);
}