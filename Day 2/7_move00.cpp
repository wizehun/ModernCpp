// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 모양을 정확히 생각해 봅시다.

	// #1. 인자가 값 타입인 경우
	// 인자를 받는 모양이 "Point other = p2" 인데,
	// 복사 생성자를 다시 호출하는 모양
	// 즉, 복사 생성자가 "무한히 호출" 되는 표현식
	// 따라서 컴파일 에러
	Point(Point other) {}

	// #2. non-const lvalue reference (&)
	// ok. 컴파일 문제 없음
	// rvalue를 받을 수 없다.
	// Point p4=foo() 에서 foo 가 return by value 면 에러!!
	Point(Point& other) {}

	// #3. const lvalue reference (const &)
	// lvalue, rvalue 를 모두 받을 수 있다.
	// 이런 이유로 복사생성자의 모양이 아래와 같은 것
	Point(const Point& other) : x(other.x), y(other.y) {}
};

Point foo()
{
	Point pt(1, 1);
	return pt;
}

int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);
	Point p4 = foo();
}




