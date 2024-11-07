#include <iostream>
#include <string>
#include <vector>

class People
{
private:
	std::string name;
	int age;

public:
	// ��� #1. 2���� �Լ� ���
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n) { name = std::move(n); }


	// ��� #2. T&& ���.
	template<typename T>

	std::enable_if_t< std::is_convertible_v<T, std::string> >

		set_name(T&& n)
	{
		name = std::forward<T>(n);
	}

};

int main()
{
	People p;

	p.set_name(3.4);
	// name = 3.4(double) �� �ڵ忡�� ����

// string �� double �� �����Ҽ� ������, 
//           double �� �����Ҽ� ����.
//	std::string s;
//	s = 3.4; // ok

//	std::string s2(3.4); // error
}








