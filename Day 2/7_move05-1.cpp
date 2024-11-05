#include <iostream>

// std::move() - 100 page

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	//	Cat c2 = c1;				// ���� ������ ȣ��
	//	Cat c3 = std::move(c1);		// �̵�
	//	Cat c4 = static_cast<Cat&&>(c1);	// �̵�

	Cat c5 = foo(); // ����� ����� �ٸ� ����
	// "ellision copy" ��� ����ȭ ������. 
}

// g++ �� "-fno-elide-constructors" ��� �ɼ��� ����ϸ�
// => (����, move) �����ڸ� ȣ������ ���� ����ȭ�� �����Ҽ� �ֽ��ϴ�.

// godbolt.org
// =>���ڵ� �ٿ��ֱ� �ϼ���

