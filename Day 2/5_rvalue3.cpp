#include <iostream>
#include <type_traits>

int main()
{
	int n = 2;

	// decltype(expression)
	// => ǥ������ Ÿ�԰� value category �� �����Ҽ� �ִ�.
	// => expression �� lvalue ��� ���� Ÿ��
	// => expression �� rvalue ��� �� Ÿ��

	if (std::is_lvalue_reference_v< decltype(n * 2)>)
		std::cout << "lvalue\n";
	else
		std::cout << "rvalue(prvalue)\n";

}