﻿// 6_enable_if1.cpp

template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
	// 핵심 : false 부분특수화 버전은 ::type 멤버가 없다.
};

// 사용법
// enable_if<bool_value, 타입> 인데
// enable_if<bool_value>	   타입 생략 가능. 생략시 void

int main()
{
	enable_if<true, int>::type  n1;	// int n1;
	enable_if<true>::type       n2;	// void n2; 
									// void 변수는 만들수 없으므로 error
	enable_if<false, int>::type n3; // "::type" 없으므로 error

	// 꼭 외울것
	enable_if<true, 타입>::type		=> "타입"
	enable_if<true>::type			=> "void"
	enable_if<false, 타입>::type	=> "::type" 없음
	enable_if<false>::type			=> "::type" 없음
}
