#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};
Circle::Circle() : Circle(1) {};
Circle::Circle(int r) { radius = r };


int main() {

}