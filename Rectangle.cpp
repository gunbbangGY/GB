#include <iostream> 
using namespace std;

class Rectangle { // Rectangle Ŭ���� �����
public:
	int width, height;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(const Rectangle& rect);
	int getArea(); // ������ ����Ͽ� �����ϴ� �Լ�
};

Rectangle::Rectangle() : Rectangle(1, 1) {}
Rectangle::Rectangle(int w, int h){width = w; height = h;}
Rectangle::Rectangle(const Rectangle& rect) {
	this->width = rect.width;
	this->height = rect.height;
}
int Rectangle::getArea() {return width * height;}

int main() {
	Rectangle rect1;
	Rectangle rect2(5, 6);
	Rectangle rect3(rect2);
	cout << "�簢���� ������ " << rect1.getArea() << endl;
	cout << "�簢���� ������ " << rect2.getArea() << endl;
	cout << "�簢���� ������ " << rect3.getArea() << endl;
}