#include <iostream> 
using namespace std;

class Rectangle { // Rectangle 클래스 선언부
public:
	int width, height;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(const Rectangle& rect);
	int getArea(); // 면적을 계산하여 리턴하는 함수
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
	cout << "사각형의 면적은 " << rect1.getArea() << endl;
	cout << "사각형의 면적은 " << rect2.getArea() << endl;
	cout << "사각형의 면적은 " << rect3.getArea() << endl;
}