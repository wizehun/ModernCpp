#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	Point() 
	{
		Point(0, 0);	// 이 코드는 생성자 호출 코드가 아닙니다.
						// "임시객체" 를 만드는 표기법 입니다.
	}

	Point() : Point(0, 0)
	{
	}

	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

