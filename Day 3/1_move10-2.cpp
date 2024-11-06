#include <iostream>
#include <string>

// 자동 생성 규칙.


// 규칙 #3. 사용자가 move 계열만 제공한 경우
// => 컴파일러는 복사계열은 만들지 않는다.
// => 복사가 필요한 코드가 있다면 "컴파일 에러" (복사 대신 move 하지 않음)

// => 복사계열의 디폴트 버전이 필요하면 "=default"로 요청하면 된다.



struct Object
{
	std::string name;

	Object() = default;
	//----------------------------------
	Object(Object&& other) noexcept : name(std::move(other.name))
	{
		std::cout << "move\n";
	}

	//Object(const Object& other) = default;
	//Object& operator=(const Object& other) = default;

	//Object& operator=(Object&& other) = default;
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
