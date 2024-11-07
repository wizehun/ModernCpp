#include <iostream>
#include <vector>
#include <type_traits>

// C++11 : move, perfect forwarding, lambda, variadic template ...
// C++20 : concept, module, ranges, coroutine ...

template<typename T>
concept container = requires(T & c)
{
	//	c.begin();
	//	c.end();

	//	std::begin(c);
	//	std::end(c);

	{ std::begin(c) } -> std::input_iterator;
	{ std::end(c) } -> std::input_iterator;

	// std::input_iterator<T> : ǥ�ؿ��� �̹� �����ϴ� ����
	//							T�� �ݺ��ڶ�� true
	//							���� ���ÿ��� <> ���� ����!!
};

template<typename T>
void foo(const T& arg)
{
	// type traits - C++11 ���, template �κ� Ư��ȭ�� ����� ���
	bool b1 = std::is_pointer_v<T>;

	// T�� �����̳����� �˰� �ʹ� ??
	// => "��� �����ؾ� �ұ�?" ���� �� �߿��� ����,,
	// => "�����̳��� ����"�� ��� �ұ�?
	// => �׷���, concept �̸��� is_ �� �������� ����.

	bool b2 = container<T>;	// T�� container concept �� �����ϸ� true

	std::string ret = (b2 == true) ? "Container!" : "no";
	std::cout << ret << std::endl;
}

class A
{
public:
	void begin() {}
	void end() {}
};

int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);

	int x[3] = { 1,2,3 };
	foo(x);

	A a;
	foo(a);
}
