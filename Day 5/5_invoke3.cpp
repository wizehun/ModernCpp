#include <iostream>

class Object
{
public:
	void foo(int a, double d) {}
};

void goo(int a, double d) {}

template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return f(std::forward<Ts>(args)...);			  // �Ϲ��Լ��� ����

	return std::invoke(f, std::forward<Ts>(args)...); // ����Լ��� ����
}

int main()
{
	chronometry(goo, 1, 3.4);				 // goo(1, 3.4)

	Object obj;
	chronometry(&Object::foo, &obj, 1, 3.4); // obj.foo(1, 3.4)
}