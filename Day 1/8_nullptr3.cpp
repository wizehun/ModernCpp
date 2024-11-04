//8_nullptr3
#include <iostream>

int main()
{
	// literal 과 타입 : 모든 값은 "타입"이 있다.

	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	false;		// bool
	nullptr;	// std::nullptr_t

	std::nullptr_t a = nullptr;

	int* p1 = a; // nullptr
}



