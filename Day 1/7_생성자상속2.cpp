#include <list>
#include <iostream>

// 기존 클래스에서 상속을 받을 때
// => 멤버 데이터를 추가하면
// => "추가된 멤버 데이터를 초기화" 해야 하므로 생성자를 만드는 것이 원칙



// 기능(함수)만 추가하려는 파생 클래스
// => 만약 MyList를 list<int>와 동일하게 사용하고 싶으면,
// => list<int> 생성자를 상속해야 한다.
class MyList : public std::list<int>
{
public:
	// C++98 방식 (생성자 다 만들어야 함)
	MyList(int sz, int value) : std::list<int>(sz, value) {}
	MyList(int sz)			  : std::list<int>(sz) {}

	// C++11 이라면 생성자 상속 가능
	using std::list<int>::list;

	void print() const
	{
		for (auto e : *this)
			std::cout << e << ", ";
		std::cout << '\n';
	}
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);
}




