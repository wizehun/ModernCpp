#include <iostream>

// CRTP : Curiously Recurring Template Pattern
// => ��� Ŭ�������� "�Ļ� Ŭ����"�� �̸��� ����ϴ� ���
// => ���� : template ���ڷ� ����
// => C++98 ���� ����ε�, ���� �θ� ���
// => C++20 Range ���̺귯���� ����ϴ� ���

template<typename T>
class Base
{
public:
	void foo()
	{
		T obj;	// Derived obj : �Ļ�Ŭ���� �̸��� ���

		std::cout << typeid(obj).name() << std::endl;
	}
};

class Derived : public Base<Derived> // �Ļ�Ŭ���� �̸� �Ѱ���
{
};

int main()
{
	Derived d;
	d.foo();
}