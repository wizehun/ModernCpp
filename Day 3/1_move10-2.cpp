#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.


// ��Ģ #3. ����ڰ� move �迭�� ������ ���
// => �����Ϸ��� ����迭�� ������ �ʴ´�.
// => ���簡 �ʿ��� �ڵ尡 �ִٸ� "������ ����" (���� ��� move ���� ����)

// => ����迭�� ����Ʈ ������ �ʿ��ϸ� "=default"�� ��û�ϸ� �ȴ�.



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
