#include <iostream>
#include <string>
using namespace std;

class Circle {
public:
	int radius; //member variable;
	double getArea(); //member function;
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	donut.radius = 1; //initialize object donut's radius = 1;
	double area1 = donut.getArea();
	std::cout << "donut's area : " << area1 << std::endl;

	Circle pizza;
	pizza.radius = 30; //initialize object pizza's radius = 30;
	double area2 = pizza.getArea();
	std::cout << "pizza's area : " << area2 << std::endl;
}