#include <memory>

class Sample
{
public:
	Sample(int* p) {}
};

int main()
{
	std::shared_ptr<Sample> p1(new Sample(0)); // ok

	//	std::shared_ptr p2 = std::make_shared<Sample>(0); // error
							// new Sample(0) �� �ǹ̸� ��ü�� �����ϰ�
							// �ش� ��ü�� �����ϴ� ����Ʈ �����͸� ��ȯ�� �޶�
							// �� �ǹ̻����� ���� ����
							// ������, 0�� ���� ������ �ʰ�
							// �ѹ� ���ļ� �����ϹǷ� error

	std::shared_ptr p2 = std::make_shared<Sample>(nullptr); // ??
}