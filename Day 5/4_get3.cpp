#include "tuple.h"
#include <iostream>

// �� �ҽ��� �ٽ� : tuple_element �����. - �̹� ǥ�ؿ��� �ֽ��ϴ�.

// primary template
// => ����ڰ� ����ϴ� ����� �� �����ؼ� ����� �˴ϴ�.
template<int N, typename T>
struct tuple_element
{
	//	using type = ? ; // Ʃ�� T�� N ��° ����� Ÿ���� ? ��
						 // ���⼭�� �˼� �����ϴ�.
						 // �˼� �ֵ��� "�κ� Ư��ȭ" �ؾ� �մϴ�.
};

// ���� Ÿ���� ���Ҽ� �ֵ��� �κ� Ư��ȭ �ؾ� �մϴ�
// => N == 0 �϶� ���� �����ؾ� �մϴ�
/*
template<typename T>
struct tuple_element<0, T>
{
	using type = ? ;	// ���� Ʃ��  T ���� 0��° ��� Ÿ�Ծ˼� �����ϴ�.
						// �߸��� �κ� Ư��ȭ
};
*/
/*
template<typename ... Ts>
struct tuple_element<0, tuple<Ts...> >
{
	using type = ? ; // tuple �̶�� ������ ��Ÿ������ ������
					 // ���� 0��° Ÿ���� �˼�����.
					 // �߸��� �κ� Ư��ȭ
};
*/

// N == 0 �ذ�
// => �Ʒ� ó�� �˰���� ������ ��Ÿ������ �κ� Ư��ȭ �ϴ� ���� �ٽ�
template<typename T, typename ... Ts>
struct tuple_element<0, tuple<T, Ts...> >
{
	using type = T;
};

// N != 0
template<int N, typename T, typename ... Ts>
struct tuple_element<N, tuple<T, Ts...> >
{
	// tuple<int, double, char> �� 2��° Ÿ����
	// tuple<     double, char> �� 1��° Ÿ���̰�
	// tuple<             char> �� 0��° Ÿ���̴�(N==0 �� �ذ�)
	using type = T;
};



template<typename TP>
void foo(TP& tp)
{
	// TP : tuple<int, double, char>
	typename tuple_element<0, TP>::type n1;
	typename tuple_element<1, TP>::type n2;

	std::cout << typeid(n1).name() << std::endl; // int
	std::cout << typeid(n2).name() << std::endl; // double
}
int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');
	foo(t3);
}