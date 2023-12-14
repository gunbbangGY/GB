#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Playfair {
	char mTable[26];
	string mPair;
	string mKey;
public:
	Playfair(string mKey, string mPair);
	void makeTable();
	void showTable();
	string makeEncryption(string mEncryption);
};

// ���� ó�� �Լ� ���� ����;
void hardmode(Playfair obj, string file_name);

Playfair::Playfair(string mKey, string mPair) {
	// mKey �ҹ��ڷ� �ٲٱ�;
	for (int i = 0; i < mKey.length(); i++) {
		if (mKey[i] > 64 && mKey[i] < 91) mKey[i] += 32;
	}
	// mKey ���� ���� ���ֱ�;
	mKey.erase(remove(mKey.begin(), mKey.end(), ' '), mKey.end());
	// mPair �Է� ���� Ȯ��;
	if (!mPair[0] || !mPair[1] || mPair[0] == mPair[2]) {
		printf("Pair input error;");
		exit(1);
	}
	// mPair �����ϱ�;
	if (mPair[0] > mPair[2]) swap(mPair[0], mPair[2]);
	// mKey �� �� pair�� ó���ϱ�;
	for (int i = 0; i < mKey.length(); i++) {
		if (mKey[i] == mPair[2]) mKey[i] = mPair[0];
	}

	this->mKey = mKey;
	this->mPair = mPair;
}

void Playfair::makeTable() {
	// a=0, z=25;
	int pair1 = mPair[0] - 97; int pair2 = mPair[2] - 97;
	// alphabets = flag table (0=!used, 1=used, 2=pair);
	int alphabets[26] = { 0 }, alp_cnt = 0;
	alphabets[pair1] = alphabets[pair2] = 2;
	// mKey �� mTable�� ä���;
	for (int i = 0; mKey[i] != NULL; i++) {
		int tmp = mKey[i] - 97;
		switch (alphabets[tmp]) {
			case 0: // !used;
				alphabets[tmp] = 1;
				mTable[alp_cnt] = mKey[i];
				alp_cnt++;
				break;

			case 1: // used;
				break;

			case 2: // pair;
				alphabets[pair1] = alphabets[pair2] = 1;
				mTable[alp_cnt] = mKey[i];
				alp_cnt++;
				break;
		}
	}
	// !used ���ĺ� mTable�� ä���
	for (int i = 0; i < 26; i++) {
		char tmp;
		switch (alphabets[i]) {
			case 0: // !used;
				alphabets[i] = 1;
				tmp = i + 97;
				mTable[alp_cnt] = tmp;
				alp_cnt++;
				break;

			case 1:	// used;
				break;

			case 2: // pair;
				alphabets[pair1] = alphabets[pair2] = 1;
				mTable[alp_cnt] = mPair[0];
				alp_cnt++;
				break;
			
		}
	}
}

void Playfair::showTable() {
	for (int col = 0; col < 5; col++) {
		for (int row = 0; row < 5; row++) {
			cout << mTable[5 * col + row] << " ";
		}
		cout << endl;
	}
	cout << endl << "���� " << mPair[0] << "�� " << mPair
		<< "�� ��Ÿ���ϴ�.";
	cout << endl << endl;
}

string Playfair::makeEncryption(string mEncryption) {
	char ch1, ch2, pair_ch;
	// �߰�ȣ �ʱ�ȭ (��� ���� 0���� �ʱ�ȭ);
	int i{}, j{}, ch1_col{}, ch1_row{}, ch2_col{}, ch2_row{}, 
		pair_col{}, pair_row{}, len{};
	// �ҹ��ڷ� �ٲٱ�;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] > 64 && mEncryption[i] < 91) mEncryption[i] += 32;
	}
	// Ư������ �� ���鹮�� �����ϱ�;
	for (i = 0; i < mEncryption.length(); i++) {
		if (ispunct(mEncryption[i])) mEncryption.erase(i--, 1);
	}
	mEncryption.erase(remove(mEncryption.begin(), mEncryption.end(), ' '), mEncryption.end());
	// Pair ���� ó���ϱ�;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] == mPair[2]) mEncryption[i] = mPair[0];
	}
	// ���� ���� ó���ϱ�;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] == mEncryption[i + 1]) {
			mEncryption.insert(i + 1, "x");
			i++;
		}
	}
	// ��� ó�� �� ���ڿ� ������ Ȧ���� �� ���� 'x' �߰�;
	if (mEncryption.length() % 2 == 1) mEncryption.append("x");
	for (i = 0; i < mEncryption.length(); i+=2) {
		// ù ��° ���� ��ġ �˾Ƴ���;
		for (j = 0; j < 25; j++) { 
			if (mEncryption[i] == mTable[j]) {
				ch1_col = j / 5;
				ch1_row = j % 5;
				break;
			}
		}
		// �� ��° ���� ��ġ �˾Ƴ���;
		for (j = 0; j < 25; j++) { 
			if (mEncryption[i + 1] == mTable[j]) {
				ch2_col = j / 5;
				ch2_row = j % 5;
				break;
			}
		}

		// �簢���� �� ��������� ��� : 1. �� ������ ���� ���� ��;
		if (ch1_col == ch2_col) { 
			ch1_row += 1; if (ch1_row > 4) ch1_row -= 5;
			ch2_row += 1; if (ch2_row > 4) ch2_row -= 5;
		}
		// �簢���� �� ��������� ��� : 2.�� ������ ���� ���� ��;
		else if (ch1_row == ch2_row) { 
			ch1_col += 1; if (ch1_col > 4) ch1_col -= 5;
			ch2_col += 1; if (ch2_col > 4) ch2_col -= 5;
		}
		// �簢���� ��������� ���;
		else swap(ch1_row, ch2_row);

		mEncryption[i] = mTable[5 * ch1_col + ch1_row];
		mEncryption[i + 1] = mTable[5 * ch2_col + ch2_row];
	}

	return mEncryption;
}

void hardmode(Playfair obj, string file_name) {
	string file_buf, buf;
	char ch;
	ifstream fin(file_name);
	if (!fin) {
		cout << "can't open a file" << endl;
		exit(1);
	}
	while (fin.get(ch)) {
		if (ch == '\n') buf.append(" ");
		else  buf.append(1, ch);

		if (ch == '.') {
			cout << buf << endl;
			cout << obj.makeEncryption(buf) << endl << endl;
			buf.clear();
		}
	}
	// '.'���� ������ ������ �ʾ� buf�� ������ �����Ҷ�;
	if (!buf.empty()) {
		cout << buf << endl;
		cout << obj.makeEncryption(buf) << endl << endl;
		buf.clear();
	}
	fin.close();
	
	return;
}

int main() {
	string filename, key, pair;
	cout << "input a file's name : ";
	getline(std::cin, filename);

	cout << "input a key : ";
	getline(cin, key);

	cout << "input a pair alphabet set (ex : a/b) : ";
	cin >> pair;

	Playfair pfair(key, pair);
	pfair.makeTable();
	pfair.showTable();
	
	hardmode(pfair ,filename);

	return 0;
}