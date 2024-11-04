// C 스타일 코드 - typedef 
typedef int DWORD;
typedef void(*F)();		// 함수 포인터 타입

// C++11 스타일 - using
using DWORD = int;
using F = void(*)();	// pName = return_type(*)(parameter_types)

int main()
{
	DWORD n; 
	F     f; 
}
