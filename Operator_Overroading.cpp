#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Power { // �������� ǥ���ϴ� �Ŀ� Ŭ����
	int kick; // �߷� ���� ��
	int punch; // �ָ����� ġ�� ��
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show(){ cout << "kick=" << kick << ',' << "punch=" << punch << endl; }
	Power operator+(Power operand2);
	Power operator+(int operand2);
	bool operator==(Power operand2);
	Power operator+=(Power operand2);
	Power operator++();
	Power operator++(int x);
	bool operator!();

	friend Power operator+(int operand1, Power operand2);
	friend Power operator+(Power operand1, Power operand2);
	friend Power operator++(Power& operand);
	friend Power operator++(Power& operand, int x);
};

Power Power::operator+(Power operand2) {
	Power tmp;
	tmp.kick = kick + operand2.kick;
	tmp.punch = punch + operand2.punch;
	
	return tmp;
}

Power Power::operator+(int operand2) {
	Power tmp;
	tmp.kick = kick + operand2;
	tmp.punch = punch + operand2;

	return tmp;
}

bool Power::operator==(Power operand2) {
	if (kick == operand2.kick && punch == operand2.punch) return true;
	else return false;
}

Power Power::operator+=(Power operand2) {
	kick = kick + operand2.kick;
	punch = punch + operand2.punch;

	return *this;
}

Power Power::operator++() {
	kick++;
	punch++;

	return *this;
}

Power Power::operator++(int x) {
	Power tmp = *this;
	kick++;
	punch++;

	return tmp;
}

bool Power::operator!() {
	if (kick == 0 && punch == 0) return true;
	else return false;
}

Power operator+(int operand1, Power operand2) {
	Power tmp;
	tmp.kick = operand1 + operand2.kick;
	tmp.punch = operand1 + operand2.kick;
	
	return tmp;
}

Power operator+(Power operand1, Power operand2) {
	Power tmp;
	tmp.kick = operand1.kick + operand2.kick;
	tmp.punch = operand1.punch + operand2.punch;

	return tmp;
}

Power operator++(Power& operand) {
	operand.kick++;
	operand.punch++;

	return operand;
}

Power operator++(Power& operand, int x) {
	Power tmp = operand;
	operand.kick++;
	operand.punch++;

	return tmp;
}
int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;
	a.show();
	b.show();
	c.show();

	c = a + 2;
	a.show();
	b.show();
	c.show();

	c = a += b;
	a.show();
	b.show();
	c.show();

	if (a == b) cout << "�� �Ŀ��� ����." << endl;
	else cout << "�� �Ŀ��� ���� �ʴ�." << endl;
}