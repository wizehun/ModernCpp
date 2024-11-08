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
	return f(std::forward<Ts>(args)...);			  // 일반함수만 가능

	return std::invoke(f, std::forward<Ts>(args)...); // 멤버함수도 가능
}

int main()
{
	chronometry(goo, 1, 3.4);				 // goo(1, 3.4)

	Object obj;
	chronometry(&Object::foo, &obj, 1, 3.4); // obj.foo(1, 3.4)
}