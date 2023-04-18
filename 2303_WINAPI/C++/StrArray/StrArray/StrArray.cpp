#include <iostream>

using namespace std;

// C 스타일 문자열 특징
// 맨 마지막 원소는 항상 '\0'
// 
// Data 영역 : 전역변수, 정적변수
// bss : 초기화 되지않은 전역변수
// data : 초기화 된 전역변수
// rodata : 읽기전용 변수(리터럴 상수 포함)

int StrLength(const char* str);
bool StrCompare(const char* str1, const char* str2);

int main()
{
	char str[12] = { 'H', 'e', 'l', 'l','o',' ','W', 'o','r', 'l', 'd', '\0'};
	char str2[12] = "Hello World"; //맨 뒤에 9 생략 Literal 상수 
	const char* str3 = "Hello World"; //rodata 영역에 있는 Hello World의 첫 메모리 주소를 받은 포인터
	const char* str4 = "junghun";

	const char* str5 = "asdfasdfasdf";
	const char* str6 = "";

	cout << str << endl;
	cout << "str1 : " << StrLength(str) << endl;
	cout << "str2 : " << StrLength(str2) << endl;
	cout << "str3 : " << StrLength(str3) << endl;
	cout << "str4 : " << StrLength(str4) << endl;
	cout << "str5 : " << StrLength(str5) << endl;
	cout << "str6 : " << StrLength(str6) << endl;
	cout << str << "와 " << str2 << "는 " << StrCompare(str, str2) << endl;
	cout << str << "와 " << str3 << "는 " << StrCompare(str, str3) << endl;
	cout << str4 << "와 " << str5 << "는 " << StrCompare(str4, str5) << endl;
	cout << str5 << "와 " << str6 << "는 " << StrCompare(str5, str6) << endl;
	cout << str6 << "와 " << str << "는 " << StrCompare(str6, str) << endl;
	

	return 0;
}

int StrLength(const char* str)
{
	int count = 0;

	while ((*(str++) != '\0')) 
		count++;
	
	return count;
}

bool StrCompare(const char* str1, const char* str2)
{
	while ((*str1) == (*str2))
	{
		if (*str1 == '\0' && *str2 == '\0') return true;
		str1++;
		str2++;
	}

	return false;
}