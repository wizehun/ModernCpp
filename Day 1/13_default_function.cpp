// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 인자가 없는 생성자를 만드는 2가지 기술
	
	// #1. 사용자가 구현
	Point() {}

	// #2. 컴파일러에게 요청
	// => 하는 일이 없다면 이 코드를 사용하는 게 좋은 코드
	Point() = default;
};

int main()
{
	Point p1;
	Point p2(1, 2);
}

