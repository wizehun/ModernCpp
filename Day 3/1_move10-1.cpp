#include <iostream>
#include <string>

// 자동 생성 규칙.


// 규칙 #2. 사용자가 복사 계열만 제공한 경우
// => 컴파일러는 move 계열 제공 안함.
// => std::move 사용 시 "복사 계열" 호출

// 핵심 : 컴파일러가 만드는 move 계열이 필요하면,
//        "=default" 로 요청하면 된다.


struct Object
{
	std::string name;

	Object() = default;
	//----------------------------------
	Object(const Object& other) : name(other.name)
	{
		std::cout << "copy\n";
	}

	Object& operator=(const Object& other) = default;

	Object(Object&& other) = default;
	Object& operator=(Object&& other) = default;
};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o1);

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}
