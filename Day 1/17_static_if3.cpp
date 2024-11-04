#include <iostream>
#include <type_traits>

// �ᱹ �Ʒ� �ڵ�� "��ũ���� ���Ǻ� ������(#ifdef...)" �� �����ϰ�
// ������ �����ϴ� �͸� �ڵ�� ����� �����ϴ� �ڵ��Դϴ�.

// �׷���, ��ũ�δ� ��ó����� ���ø� ���� T�� ������ ����� �����ϴ�.

// �Ʒ� �ڵ�� �����Ϸ��� �ϰ� �ǹǷ� �پ��ϰ� T�� �����Ҽ� �ֽ��ϴ�.

template<typename T>
void foo(T& a)
{
	// std::is_pointer_v<T> : T�� ������ ���� ����
	//						  ������ �ð��� ����(����ϳ� �ڼ���)
	if constexpr (std::is_pointer_v<T>)
	{
		std::cout << "�����Ϳ� ����ȭ�� �˰���\n";
	}
	else if constexpr (std::is_reference_v<T>)
		std::cout << "���۷��� ����ȭ�� �˰���\n";
	else
		std::cout << "�׿� �˰���\n";
}
int main()
{
	int n = 0;
	foo(&n);
}