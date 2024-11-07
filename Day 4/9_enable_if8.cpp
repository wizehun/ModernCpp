#include <iostream>
#include <type_traits>

template<typename T>
concept pointer = std::is_pointer_v<T>;

template<typename T>
concept not_pointer = !std::is_pointer_v<T>;

// �Ʒ� 2�� ��� ���ø� �Դϴ�.
void printv(const pointer auto& v)
{
	std::cout << v << " : " << *v << std::endl;
}

void printv(const not_pointer  auto& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}