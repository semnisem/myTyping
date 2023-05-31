//���α׷�
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
		std::cout << "************* �ѱ� Ÿ�ڿ��� Ȩ *************" << endl;
		std::cout<< "   ---------- selection -----------" << endl;
		std::cout << "  | 1.������ �����Ϸ� ����          |" << endl;
		std::cout << "  | 2.���� ����                     |" << endl;
		std::cout << "  | 3.ª���� ����                     |" << endl;
		std::cout << "  | 4.��� ����                     |" << endl;
		std::cout << "  | 5.���� ��� ����                |" << endl;
		std::cout << "  | 6.Ÿ�ڿ��� �׸��ҷ���           |" << endl;
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
			std::cout << "Ÿ�� ���α׷��� �����մϴ�. \n" << endl;
			return 0;
		default:
			break;
		}
	}
	return 0;
}