#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
	string s;
	cout << "���� ���ڿ��� �Է� : " << endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;
	while (true) {
		int fIndex = s.find('+', startIndex);
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}
		int count = fIndex - startIndex;
		string part = s.substr(startIndex, count);
		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex + 1;
	}

	cout << "������ ���� : " << sum;
}