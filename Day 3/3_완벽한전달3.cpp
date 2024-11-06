void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry						hoo(int&&)
// hoo(10) ================================================> ok
// chronometry(10) =====> int&& arg = 10
//						  arg �� lvalue 
//						  hoo(arg) ===================> error. arg �� lvalue
//						rvalue �� �����鼭 lvalue�� ����
//						  hoo(static_cast<int&&>(arg) =======> ok

template<typename F> void chronometry(F f, int&& arg)
{
	//	f(arg); // error

		// main ===> chronometry �� �������� rvalue(10) ���µ�.. 
		// "int&& arg = 10" ���� �����鼭 arg �� lvalue �� �Ǿ���.
		// forwarding �Ҷ��� �ٽ� rvalue �� �����ؼ� ����
	f(static_cast<int&&>(arg));
}

int main()
{
	hoo(10);

	chronometry(hoo, 10);

}




