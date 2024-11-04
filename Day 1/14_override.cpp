// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 가상 함수 재정의시 실수(오타)
	// => 에러가 발생하지 않습니다.
	// => 새로운 함수를 만들었다고 컴파일러가 생각
	virtual void fooo()			{}
	virtual void goo(double a)	{}
	virtual void hoo() const	{}

	// 위 문제를 해결하기 위해 C++11 에서 "override" 키워드 제공
	// => 새로운 함수가 아닌, 기반 클래스 함수를 재정의한다고 알려줌
	// => 오타 발생 시 에러 (무조건 사용하기)
	virtual void fooo()			override {}
	virtual void goo(double a)	override {}
	virtual void hoo() const	override {}

	// final 키워드 붙이면 더이상 override 불가
	virtual void foo()			final {}
};


int main()
{
}
