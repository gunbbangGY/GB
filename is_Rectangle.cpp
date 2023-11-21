#include <iostream>
using namespace std;

class Rectangle { // Rectangle Ŭ���� �����
public:
	int width, height;
	Rectangle();
	Rectangle(int n);
	Rectangle(int w, int h);
	bool isSquare(); // ���簢������ �Ǵ��ϴ� �Լ�
};

Rectangle::Rectangle() : Rectangle(1, 1) {}
Rectangle::Rectangle(int n) : Rectangle(n, n) {}
Rectangle::Rectangle(int w, int h) { width = w; height = h; }

bool Rectangle::isSquare() {
	if (width == height) return true;
	else return false;
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢��" << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢��" << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢��" << endl;
}