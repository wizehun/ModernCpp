#include <iostream>
#include <vector>
#include <list>
/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();

	std::cout << n << std::endl;
}
*/
/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// T : std::list<double>
	// 
	// T::value_type => std::list<double>::value_type => double

	typename T::value_type n = v.front();

	std::cout << n << std::endl;
}

int main()
{
	//	std::vector<int> v = { 1,2,3,4 };
	//	std::vector<double> v = { 1,2,3,4 };
	std::list<double> v = { 1,2,3,4 };

	print_first_element(v);
}

// ���ø����� ������� �����̳ʸ� ����Ҷ���
// ����� Ÿ���� �˰� �������� �ֽ��ϴ�.
// �� "print_first_element" ó��

// �׷��� STL �� ��� �Ʒ� ó���Ǿ� �ֽ��ϴ�.
template<typename T> class list
{
public:
	using value_type = T; // <== �ٽ� ����

};

std::list<int> s = { 1,2,3 };
std::list<int>::value_type n = s.front(); // int n = s.front()

// cppreference.com ���� std::list �˻�

// STL��
// "��� �Լ�", "��� ����" �ܿ�
// "��� Ÿ��" �̶�� ������ �ֽ��ϴ�.
/*
template<typename T>
class List
{
	// ��� Ÿ��
	using value_type = T;
	using iterator = _list_iterator;
	using size_type = std::size_t;

	// ��� ����Ÿ

	// ��� �Լ� 

};
*/