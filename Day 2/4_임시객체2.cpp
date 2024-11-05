// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	// #1. 임시 객체는 등호의 왼쪽에 올 수 없다. (임시객체는 rvalue 이다)
	pt.x = 10;				// ok.
	Point(1, 2).x = 10;		// error.
						
	// #2. 임시 객체는 주소를 구할 수 없다. (단, 생성자에서 this 사용은 가능)
	Point* p1 = &pt;			// ok.			
	Point* p2 = &Point(1, 2);	// error.
							
	// #3. 임시 객체는 non-const 참조로 가리킬 수 없다. (변경 가능성 x)
	Point& r1 = pt;				// ok.
	Point& r2 = Point(1, 2);	// error.

	// #4. 임시 객체는 const & 참조로 가리킬 수 있다.
	const Point& cr = Point(1, 2);	// ok.
		// => 이 순간 임시객체의 수명은 cr의 수명으로 연장된다. (계속 참조는 해야되므로)
		// => life-time extension 이라는 개념

	// #5. C++11을 만들 때 "상수성없이 임시객체를 가리키고 싶었습니다."
	// => move, perfect forwarding 을 위해서
	// => 그래서 새로운 참조를 만들게 된다.
	Point&& rr = Point(1, 2); // rvalue reference
}





