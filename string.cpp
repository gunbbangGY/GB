#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "���ڿ��� �Է��ϼ���(�ѱ� �ȵ�) " << endl;
	getline(cin, s, '\n'); // ���ڿ� �Է�
	int len = s.length(); // ���ڿ��� ����

	for (int i = 0; i < len; i++) {
		string last = s.substr(len-1, 1); // �� ���� ���� 1���� ���ڿ��� �и�
		string sub = s.substr(0, len - 1); // �� ���� ���� 1���� ������ ������ ���ڵ��� ���ڿ��� �и�
		s = last + sub; // �� ���ڿ��� �����Ͽ� ���ο� ���ڿ��� ����
		cout << s << endl;
	}
}
