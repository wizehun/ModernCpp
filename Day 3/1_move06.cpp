#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	//	Object(Object&&)      { std::cout << "move" << std::endl; }
};
int main()
{
	// #1. move �����ڸ� ������ ���� Ŭ������ ���ؼ� std::move() ����ߴٸ� ?
	// => 
	Object o1;
	Object o2 = std::move(o1);
	// static_cast<Object&&>(o1) �� �ǹ��ϻ�!!!
	// ���� �� �ڵ��
	// 1. move �����ڰ� �ִٸ� ����ϰ�
	// 2. ���ٸ� ���� �����ڸ� ����Ѵ�.
	// => �ᱹ, move �����ڰ� ���� Ÿ�Կ� ���ؼ��� std::move() ��밡��
	// => ��, move ȿ���� ����.



// #2. primitive type �� ���ؼ� std::move �� ����ߴٸ� ?
// =>
	int n1 = 10;
	int n2 = std::move(n1);
	// static_cast<int&&>(n1) �̹Ƿ� �ƹ� ȿ���� �����ϴ�


	int* p1 = new int;
	int* p2 = std::move(p1);
	// ���� �ƹ� ȿ�� �����ϴ�.
	// p1 �� 0 �� �Ǵ°� �ƴմϴ�.



// #3. STL �� ��κ� move �����ڸ� �����մϴ�.
	std::vector<int> v1 = { 1,2,3,4 };
	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl; // 0
}
