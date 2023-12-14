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

// 파일 처리 함수 원형 선언;
void hardmode(Playfair obj, string file_name);

Playfair::Playfair(string mKey, string mPair) {
	// mKey 소문자로 바꾸기;
	for (int i = 0; i < mKey.length(); i++) {
		if (mKey[i] > 64 && mKey[i] < 91) mKey[i] += 32;
	}
	// mKey 공백 문자 없애기;
	mKey.erase(remove(mKey.begin(), mKey.end(), ' '), mKey.end());
	// mPair 입력 오류 확인;
	if (!mPair[0] || !mPair[1] || mPair[0] == mPair[2]) {
		printf("Pair input error;");
		exit(1);
	}
	// mPair 정렬하기;
	if (mPair[0] > mPair[2]) swap(mPair[0], mPair[2]);
	// mKey 값 중 pair값 처리하기;
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
	// mKey 값 mTable에 채우기;
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
	// !used 알파벳 mTable에 채우기
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
	cout << endl << "문자 " << mPair[0] << "는 " << mPair
		<< "을 나타냅니다.";
	cout << endl << endl;
}

string Playfair::makeEncryption(string mEncryption) {
	char ch1, ch2, pair_ch;
	// 중괄호 초기화 (모든 변수 0으로 초기화);
	int i{}, j{}, ch1_col{}, ch1_row{}, ch2_col{}, ch2_row{}, 
		pair_col{}, pair_row{}, len{};
	// 소문자로 바꾸기;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] > 64 && mEncryption[i] < 91) mEncryption[i] += 32;
	}
	// 특수문자 및 공백문자 제거하기;
	for (i = 0; i < mEncryption.length(); i++) {
		if (ispunct(mEncryption[i])) mEncryption.erase(i--, 1);
	}
	mEncryption.erase(remove(mEncryption.begin(), mEncryption.end(), ' '), mEncryption.end());
	// Pair 문자 처리하기;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] == mPair[2]) mEncryption[i] = mPair[0];
	}
	// 같은 문자 처리하기;
	for (i = 0; i < mEncryption.length(); i++) {
		if (mEncryption[i] == mEncryption[i + 1]) {
			mEncryption.insert(i + 1, "x");
			i++;
		}
	}
	// 모든 처리 후 문자열 개수가 홀수일 시 끝에 'x' 추가;
	if (mEncryption.length() % 2 == 1) mEncryption.append("x");
	for (i = 0; i < mEncryption.length(); i+=2) {
		// 첫 번째 문자 위치 알아내기;
		for (j = 0; j < 25; j++) { 
			if (mEncryption[i] == mTable[j]) {
				ch1_col = j / 5;
				ch1_row = j % 5;
				break;
			}
		}
		// 두 번째 문자 위치 알아내기;
		for (j = 0; j < 25; j++) { 
			if (mEncryption[i + 1] == mTable[j]) {
				ch2_col = j / 5;
				ch2_row = j % 5;
				break;
			}
		}

		// 사각형이 안 만들어지는 경우 : 1. 두 문자의 행이 같을 때;
		if (ch1_col == ch2_col) { 
			ch1_row += 1; if (ch1_row > 4) ch1_row -= 5;
			ch2_row += 1; if (ch2_row > 4) ch2_row -= 5;
		}
		// 사각형이 안 만들어지는 경우 : 2.두 문자의 열이 같을 때;
		else if (ch1_row == ch2_row) { 
			ch1_col += 1; if (ch1_col > 4) ch1_col -= 5;
			ch2_col += 1; if (ch2_col > 4) ch2_col -= 5;
		}
		// 사각형이 만들어지는 경우;
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
	// '.'으로 파일이 끝나지 않아 buf의 내용이 잔재할때;
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