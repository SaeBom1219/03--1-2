#include <iostream>
using namespace std;

/*
1. 함수 3개 선언
2. main에서 문자열 저장 공간 동적할당
3. 문자열 한 줄 입력
4. GetLength() 호출해서 길이 출력
5. PrintString() 호출해서 원래 문자열 출력
6. PrintReversedString() 호출해서 거꾸로 문자열 출력
7. 동적할당 해제
8. GetLength() 함수 정의
9. PrintString() 함수 정의
10. PrintReversedString() 함수 정의
*/

int GetLength(char* str);  // 1. 함수선언
void PrintString(char* str);
void PrintReversedString(char* str);

int main() {

	/*정적배열 char str[100]*/

	char* str = new char[100]; // 2. 동적할당


	/* cin >> str;은 공백 전까지만 받아서 쓰면 안됨*/

	cin.getline(str, 100); //3.문자열 한줄 입력-getline : 공백까지 포함해서 한 줄 전체 입력받는 함수

	cout << GetLength(str) << endl; // 4. 길이 출력

	PrintString(str); // 5. 원래 문자열 출력
	cout << endl;

	PrintReversedString(str); // 6. 거꾸로 문자열 출력
	cout << endl;

	delete[] str; // 7. 동적할당 해제

}

int GetLength(char* str) { // 8. GetLength() 함수 정의
	int length = 0;

	while (*str != '\0') {
		length++;
		str++;
	}
	return length;
}

void PrintString(char* str) { // 9. PrintString() 함수 정의

	while (*str != '\0') {
		cout << *str;
		str++;
	}
}

void PrintReversedString(char* str) { // 10. PrintReversedString() 함수 정의
	char* p = str + GetLength(str) - 1;

	while (p >= str) {
		cout << *p;
		p--;
	}
}

// hello world
// pandora cube
