class Object
{
public:
	void f1(int code) {}
	static void f2(int code) {}
};
void foo(int n) {}

int main()
{
	// #1. 일반 함수포인터에 멤버함수의 주소를 담을 수 없다.
	// #2. 일반 함수포인터에 static 멤버함수의 주소는 담을 수 있다.
	void(*f1)(int) = &foo;			// ok.
	void(*f2)(int) = &Object::f1;	// error.
	void(*f3)(int) = &Object::f2;	// ok.

	// 멤버함수의 주소를 담는 "멤버함수포인터" 만들기
	void(Object::*f)(int) = &Object::f1;

	// #1. 멤버함수포인터로 호출하기
	f(0);	// error. 객체가 없다. ( obj.f1(0) 처럼 호출되어야 함 )

	// #2. 객체 생성해서 멤버함수포인터로 호출하기
	Object obj;
	obj.f(10);	// error. obj 안에 "f" 라는 함수가 없다.

	// #3. pointer to member 라는 연산자가 필요하다. ( .* 또는 ->* )
	obj.*f(10);	// error. 연산자 우선순위 문제 
				// .* 보다 ( 연산자가 우선순위가 높다.

	// #4. 연산자 우선순위 지정
	(obj.*f)(10);	// ok.
					// 이 코드가 멤버함수포인터로 멤버함수를 호출하는 코드
}
