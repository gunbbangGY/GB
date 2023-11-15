#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	char* title; //���� ���ڿ�
	int price; //����
public:
	Book(const char* title, int price);
	~Book();
	Book(const Book& book);
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
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
	if (this->title) delete[] this->title; // title�� �Ҵ�� �޸𸮰� ������ ��ȯ
	int len = strlen(title);
	this->title = new char[len + 1]; // title�� ���� ��ŭ �� �޸� �Ҵ�
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ������ ȣ���
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();

	return 0;
}