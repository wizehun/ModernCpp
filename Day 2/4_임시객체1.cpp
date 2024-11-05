// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
	Point pt(1, 2);		// 이름있는 객체 (named object)
						// 수명 : 자신을 선언한 { } 을 벗어날 때 파괴

	Point (1, 2);		// 이름없는 객체 (unnamed object)
						// 수명 : 자신을 선언한 문장의 끝에서 파괴
						// 임시객체(temporary) 라고도 한다.

	std::cout << "-------" << std::endl;
}





