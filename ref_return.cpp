#include <iostream>
using namespace std;

char c = 'a';

char& find() { // char Ÿ���� ���� ����
	return c; // ���� c�� ���� ���� ���� 
}

int main() {
	char a = find(); // a = 'a'�� ��

	char& ref = find(); //  ref�� c�� ���� ����
	ref = 'M'; // c= 'M'

	find() = 'b'; // c = 'b'�� ��

	cout << a << endl << ref << endl << find();
}
