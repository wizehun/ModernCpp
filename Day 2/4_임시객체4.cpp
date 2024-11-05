// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {}  // call by value     : 복사본 생성됨
void f2(Point& pt) {}  // call by reference : 복사본 생성 안됨


Point pt(1, 2);

Point foo()			// return by value : 임시객체를 반환 
{
	return pt; // pt를 복사한 임시객체 생성 -> 반환
}

Point& goo()		// return by reference : 임시객체를 만들지 마
{
	return pt;
}

int main()
{
	foo().x = 10;	// error. "임시객체.x = 10"
	goo().x = 10;	// ok.	  "pt.x = 10"
}

// 주의 : 지역변수는 절대로 return by reference 하면 안된다.
// => 함수 종료와 동시에 파괴되므로 알 수 없어짐






