#include <iostream>
using namespace std;

char c = 'a';

char& find() { // char 타입의 참조 리턴
	return c; // 변수 c에 대한 참조 리턴 
}

int main() {
	char a = find(); // a = 'a'가 됨

	char& ref = find(); //  ref는 c에 대한 참조
	ref = 'M'; // c= 'M'

	find() = 'b'; // c = 'b'가 됨

	cout << a << endl << ref << endl << find();
}
