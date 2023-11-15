#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	char* title; //제목 문자열
	int price; //가격
public:
	Book(const char* title, int price);
	~Book();
	Book(const Book& book);
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book() {	delete[]title; }

Book::Book(const Book& book) {
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
	this->price = book.price;
}

/*
Book::Book(const Book& book) {
	strcpy(this->title, title);
	this->price = book.price;
}
*/

void Book::set(const char* title, int price) {
	if (this->title) delete[] this->title; // title에 할당된 메모리가 있으면 반환
	int len = strlen(title);
	this->title = new char[len + 1]; // title의 길이 만큼 새 메모리 할당
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사 생성자 호출됨
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}