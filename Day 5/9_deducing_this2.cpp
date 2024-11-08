#include <iostream>

struct Point
{
	int x = 0;
	int y = 0;

	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	void print() const
	{
		std::cout << x << std::endl;
	}
};

int main()
{
	const Point pt;

	pt.x = 10;		// error. x는 public 이지만 pt가 상수객체이므로
	pt.set(10, 20);	// error. set(&pt, 10, 20)
	pt.print();		// error. print(&pt) 
						// (바꾸는 것도 없는데?)
						// => 보통 클래스 내부에서는 선언만 함 (바꾸는지 여부 모름)
						// => 실제이유 : this 위치에 &pt가 넘어감 (const를 넘길 수 없음)
}

// 상수객체는 상수 멤버 함수만 호출 가능합니다.
// 
// C++에서 상수 객체는 아주 널리 사용됩니다.
// => 함수 인자가 "const Point&" 는 너무 많습니다.

// 멤버 함수중 값을 변경하지 않으면 반드시 상수 멤버 함수로 해야 합니다.