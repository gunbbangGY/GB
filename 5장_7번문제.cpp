#include <iostream>
#include <string>
using namespace std;

class MyIntStack {
	int p[10]; // �ִ� 10���� ���� ����
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack();
	bool push(int n); // ���� n Ǫ��. �� �� ������ flase, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ����
};

MyIntStack::MyIntStack() {
	tos = 0;
}

bool MyIntStack::push(int n) {
	if (tos >= 10) return false;
	else {
		p[tos] = n;
		tos++;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (!tos) return false;
	else {
		n = p[tos];
		tos--;
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}
