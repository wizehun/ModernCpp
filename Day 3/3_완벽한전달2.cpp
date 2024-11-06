#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
// #1. int& �� int&& ������ ���� �־�� �մϴ�.
// #2. �Ʒ� �ڵ�� �� �Ѱ����� ������ �ֽ��ϴ�. hoo() �� ������ ������

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // error
	// ���ΰ� �ذ�å�� �����ҽ�����.. 

	int n = 10;
	chrometry(foo, 10);
	chrometry(goo, n);

	std::cout << n << std::endl;
}




