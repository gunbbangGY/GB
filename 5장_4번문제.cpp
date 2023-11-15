#include <iostream>
#include <string>
using namespace std;

bool bigger(int a, int b, int& big);

int main() {
	int num1, num2, result;
	cout << "첫 번째 정수 입력 >> ";
	cin >> num1;
	cout << "두 번째 정수 입력 >> ";
	cin >> num2;
	if (bigger(num1, num2, result)) cout << "두 정수는 크기가 같습니다";
	else cout << "두 정수 중 더 큰 수는 " << result;
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