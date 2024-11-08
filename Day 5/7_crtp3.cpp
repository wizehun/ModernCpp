#include <iostream>

// class template ���鶧 T�� ������� ����� �ִٸ�
// => ���ø��� �ƴ� ��� Ŭ������ ���� �����ض�
// => "thin template" �Ǵ� "template hoisting" �̶�� ���

// github.com/webkit  

// source/wtf/wtf    RefCounted.h ���� ������


// ���� "C++ IDioms" �˻���   1��° ��ũ

class Window
{
	int handle;
	int color;
public:
	void move() {}
	void show() {}

	void click() { std::cout << "window click\n"; }
	void keydown() {}
};

template<typename T>
class MsgWindow : public Window
{
public:
	void msg_loop()
	{
		static_cast<T*>(this)->click();
	}
};

class MainWindow : public MsgWindow<MainWindow>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.msg_loop();
}