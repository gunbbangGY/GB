#include <iostream>
#include <string>
using namespace std;

bool bigger(int a, int b, int& big);

int main() {
	int num1, num2, result;
	cout << "ù ��° ���� �Է� >> ";
	cin >> num1;
	cout << "�� ��° ���� �Է� >> ";
	cin >> num2;
	if (bigger(num1, num2, result)) cout << "�� ������ ũ�Ⱑ �����ϴ�";
	else cout << "�� ���� �� �� ū ���� " << result;
}

bool bigger(int a, int b, int& big) {
	if (a == b) {
		return true;
	}
	else if(a > b) {
		big = a;
		return false;
	}
	else {
		big = b;
		return false;
	}
}