// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// 규칙 #1. non-const lvalue reference (&) 는 lvalue 만 가리킬 수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error.

	// 규칙 #2. const lvalue reference (&) 는 lvalue, rvalue 모두 가리킬 수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok

	// 규칙 #3. rvalue reference (&&) 는 rvalue 만 가리킬 수 있다. (C++11)
	// => 의도 : 상수성 없이 임시객체를 가리키고 싶다.
	// => move, perfect forwarding 을 위해 만든 것
	Point&& r5 = pt;			// error.
	Point&& r6 = Point(0, 0);	// ok

	// const rvalue reference 는 어떤가요 ?
	// => rvalue 만 가리킬 수 있다. (동일)
	// => 그런데 현재까지는 사용하는 경우가 없다.
	// => 그래서 대부분의 문서에서 다루지 않는다. (move 배운 후 이해)
}
