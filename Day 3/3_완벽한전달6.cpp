#include <iostream>

int& foo(int a, double d, int& n) { n = 100; return n; }

void f1() {}
void f2(int n) {}

// ���� : �Ϻ��� ������ �Ϸ���
// 1. ���ڸ� ������ T&& �� �޾ƾ� �մϴ�.
// 2. ���ڸ� �ٸ� �Լ��� ������ "std::forward<T>(arg)" �� ����� �մϴ�.
// 3. ��ȯ���� �Ϻ��� �����ַ��� "decltype(auto)" �� �ϼ���
// 4. ���� ������ ������� �Ϸ��� "�������� ���ø�" ���
//    (�ݿ��� ���Ե˴ϴ�.)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;

	chronometry(f1); // ���ھ��� �Լ�
	chronometry(f2, 3);

	int& ret = chronometry(foo, 5, 3.4, n);

	std::cout << n << std::endl; // 100
	ret = 300;
	std::cout << n << std::endl; // 300
}




