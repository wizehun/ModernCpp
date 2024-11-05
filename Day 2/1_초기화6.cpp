// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

	//Point() {}
	Point() = default;
};

int main()
{
	int n1{ 0 };	
	int n2 = { 0 }; 
	int n3;			
	int n4{};		

	std::cout << n4 << std::endl; // 0

	Point pt{};	// 1. 사용자가 만든 디폴트 생성자가 있으면 호출
				// 2. 사용자가 만든 생성자가 없거나, =default 생성자이면
				//	  모든 멤버를 0 으로

	std::cout << pt.x << std::endl;
}


