#include <vector>

class Object
{
	int data = 0;
public:
	// �Ʒ� 2���� ��ȯ Ÿ���� �����ϰ�� ������ ������ �����մϴ�.
	// => template ���� �ڵ������ϸ� ���� ������� ?
	// => �׷���, template ����Ϸ��� ������ Ÿ��(this)�� ���� �ڵ带����
	//    �ؾ� �մϴ�. �׷���, �Ʒ� �ڵ�� this �� �巯���� �ʽ��ϴ�.
	/*
	int& get()					// int& get(Point* this)
	{
		return data;
	}
	const int& get() const		// const int& get(const Point* this)
	{
		return data;
	}
	*/

	// ��� ��� �Լ� ������ "explicit object parameter"�� ����� ���ô�.
	// => ���� C++98 �� const �� �Լ� () �ڿ� �ִµ�
	// => �Ʒ� �ڵ�� �Լ� ���ڷ� �Ǿ����ϴ�.
	/*
	int& get(this Point& self)
	{
		return self.data;
	}
	const int& get(this const Point& self)
	{
		return self.data;
	}
	*/
	// �Ʒ� ó�� �ϸ� 2���� �ڵ������Ҽ� �ֽ��ϴ�.
	// "this �� Ÿ��(T)" �� ��� �Լ� ȣ���Ҷ�
	// => ��ü�� ������ ���� �߷еɼ� �ֽ��ϴ�.
	// => obj.get()  :  T= Point �߷�
	// => cobj.get() :  T= const Point �߷�

	// this �� Ÿ���� �߷еɼ� �ִٰ� �ؼ�.. �� ����� ������
	// "deducing this" ( this �߷� )

	template<typename T>
	std::conditional_t< std::is_const_v<T>, const int&, int&>
		get(this T& self)
	{
		return self.data;
	}
};

int main()
{
	Object obj;
	const Object cobj;

	int n1 = obj.get();  // get(obj) => get(Point&)		  ����
	obj.get() = 0;

	int n2 = cobj.get(); // get(cobj)=> get(const Point&) ����

}

// �����Ҷ� recursive lambda �˻��� ������
// => ���� ǥ�������� ��� ȣ�� �����
// => C++23 ���� ����. explicit object parameter ��!!