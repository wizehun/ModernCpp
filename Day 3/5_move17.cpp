#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// ���ڰ� 2���� setter
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}

	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	*/
	// ���ڰ� 2���̻��� setter�� ���� ��ó�� ���� ������ ����
	// T&& �� ����ϴ� ���� �����ϴ�.

	template<typename T1, typename T2>
	// T1, T2�� string�� ȣȯ�������� Ÿ���̸� ������� ������ �� �ʿ� 
	// => enable_if ���.. ���� 
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// �����ڵ� �ᱹ "setter" �Դϴ�.
	// �Ʒ� �ڵ�� move���� �ȵ˴ϴ�.
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}

	template<typename T1, typename T2>
	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), address(std::forward<T2>(a))
	{
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p(name, std::move(addr));
	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));
}







