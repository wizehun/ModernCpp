#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// �Ʒ� ĳ������ rvalue ĳ�����Դϴ�. ( T&& �� �ƴ� int&& �̹Ƿ�)
//	static_cast<int&&>(arg);


	// �Ʒ� ĳ������ rvalue ĳ������ �ƴմϴ�.
	// chronometry �� 2��° ���ڷ�
	// rvalue(10) �� �����ϸ� (�����鼭 arg �� lvalue�� �Ȱ��� �ٽ�) rvalue ĳ����
	// lvalue(n)  �� �����ϸ� (�ʿ���� ĳ����������)               lvalue ĳ����
//	static_cast<T&&>(arg);


//	f(static_cast<T&&>(arg)); // �� �ڵ嵵 ��Ȯ�� ���� ���� �ڵ��Դϴ�.
	f(std::forward<T>(arg));  // std::forward<T>() �� �ϴ� ����
	// �� �ڵ�� ����(ĳ����)�մϴ�.
	// �� ���� T&& �� �ƴ� T �Դϴ�.
}

int main()
{
	int n = 10;

	chronometry(foo, 10);

	chronometry(goo, n);
}




