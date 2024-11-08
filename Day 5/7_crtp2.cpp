#include <iostream>

// CRTP �� ����ؼ� �����Լ��� �ƴ� �ڵ带 �����Լ� ó�� �����ϰ� �ϴ� ���

template<typename T>
class Window
{
public:
	void msg_loop()		// void msg_loop(Window* this)	
	{
		//		click();		//	this->click()

		static_cast<T*>(this)->click();
	}
	void click() { std::cout << "window click\n"; }
};

class MainWindow : public Window<MainWindow>
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.msg_loop();
}