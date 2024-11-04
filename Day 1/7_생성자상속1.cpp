// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};

class Derived : public Base
{
public:
	// "생성자는 상속되지 않는다" 라는 문법이 있습니다.
	// C++11 부터 생성자 상속을 가능하게 할 수 있습니다.
	using Base::Base;

	// 위 문법이 없다면 아래 처럼 해야 합니다.
	Derived() {}
	Derived(int n) : Base(n) {}
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
