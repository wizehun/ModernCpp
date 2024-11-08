#include <iostream>

// CRTP : Curiously Recurring Template Pattern
// => 기반 클래스에서 "파생 클래스"의 이름을 사용하는 기술
// => 원리 : template 인자로 전달
// => C++98 시절 기술인데, 요즘 널리 사용
// => C++20 Range 라이브러리가 사용하는 기술

template<typename T>
class Base
{
public:
	void foo()
	{
		T obj;	// Derived obj : 파생클래스 이름을 사용

		std::cout << typeid(obj).name() << std::endl;
	}
};

class Derived : public Base<Derived> // 파생클래스 이름 넘겨줌
{
};

int main()
{
	Derived d;
	d.foo();
}