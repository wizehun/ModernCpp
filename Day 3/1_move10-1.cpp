#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.


// ��Ģ #2. ����ڰ� ���� �迭�� ������ ���
// => �����Ϸ��� move �迭 ���� ����.
// => std::move ��� �� "���� �迭" ȣ��

// �ٽ� : �����Ϸ��� ����� move �迭�� �ʿ��ϸ�,
//        "=default" �� ��û�ϸ� �ȴ�.


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
