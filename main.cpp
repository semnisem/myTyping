//프로그램
#include "data.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string word(Dataset& data);
string sentence(Dataset& data);
string essay(Dataset& data);
void write(string record);
void read();

int main() {
	
	Dataset ds;
	std::cout << "*******************************************" << endl;
	std::cout << "  --------- \\ \\    / /-------- |  _____|" << endl;
	std::cout << "  ----| |--- \\ \\  / / | |---| || |" << endl;
	std::cout << "      | |     \\ \\/ /  | |---| || |_____" << endl;
	std::cout << "      | |      |  |   |  _____||  _____|" << endl;
	std::cout << "      | |      |  |   | |      | |_____ " << endl;
	std::cout << "      | |      |  |   | |      |_______|" << endl;
	std::cout << endl << endl;

	while (true) {
		std::cout << "************* 한글 타자연습 홈 *************" << endl;
		std::cout<< "   ---------- selection -----------" << endl;
		std::cout << "  | 1.데이터 편집하러 가기          |" << endl;
		std::cout << "  | 2.낱말 연습                     |" << endl;
		std::cout << "  | 3.짧은글 연습                     |" << endl;
		std::cout << "  | 4.긴글 연습                     |" << endl;
		std::cout << "  | 5.성적 기록 보기                |" << endl;
		std::cout << "  | 6.타자연습 그만할래요           |" << endl;
		std::cout << "   --------------------------------" << endl;
		std::cout << " I want to go to : ";

		int user;
		cin >> user;
		std::cout << endl;

		switch (user) {
		case(1):
			ds.edit();
			break;
		case(2):
			write(word(ds));
			break;
		case(3):
			write(sentence(ds));
			break;
		case(4):
			write(essay(ds));
			break;
		case(5):
			read();
			break;
		case(6):
			std::cout << "타자 프로그램을 종료합니다. \n" << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}