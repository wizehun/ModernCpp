#include <iostream>
#include <string>
#include <vector>

class People
{
private:
	std::string name;
	int age;

public:
	// move ���� setter ����� ��

	// ��� #1. 2���� �Լ� ���
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n) { name = std::move(n); }


	// ��� #2. T&& ���.
	template<typename T>
	void set_name(T&& n)
	{
		//		name = n;					// 1. �׻� ����
		//		name = std::move(n);		// 2. �׻� �̵�
		name = std::forward<T>(n);	// 3. lvalue �� ������ lvalue ĳ����(����)
		//    rvalue �� ������ rvalue ĳ����(�̵�)
	}

	// ��� #1. set_name(const std::string& n) �� �Լ���
	// => lvalue, const lvalue �� ��� �ذ��Ѵ�.

	// ��� #2 ��
	// => set_name(std::string& n) �� �����ϰ�
	// => set_name(const std::string& n) �� ����


	// �׷��� ����, ��� #1 �� �����մϴ�.
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// T&& : string&	
	p.set_name(std::move(s2));	// T&& : string&&

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}







