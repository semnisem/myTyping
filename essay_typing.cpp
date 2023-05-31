#include "data.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string essay(Dataset& data) {

	std::cout << "************ ��ۿ��� ���� ************" << endl;
	clock_t start, finish; //�ð� üũ ���ؼ�
	double duration; //���ܴ� �ð�
	double total = 0.0; //��ü �ð�
	double speed; //�ӵ�(�� ������ �ð�)=(��ü�ð�/��ü���� ���� ��)


	int size = data.getEsize(); //��ü���� ����
	double rate; //����� = (�����ε���+1)/��ü���ܰ���
	int count = 0; //���ܴ� Ÿ�� (Ÿ�� = size/2 (�ѱ���2bytes�̹Ƿ�))
	int counts = 0; //���� Ÿ��

	int wrong = 0; //���� ��Ÿ ��
	double accuracy; //������Ȯ��=100-100*(������Ÿ��/����Ÿ��)

	cin.ignore(); //���� ����ֱ�*

	for (int i = 0; i < size; i++) {

		//Ÿ������ ���� ���
		while (data.one_essay(i) == "") {
			i++;
		}
		if (i == size)
			break;

		string context = data.one_essay(i);
		std::cout << context << " [" << i << "]\n>> ";

		///���ÿ� �°� Ÿ����
		start = clock();
		string user;
		getline(cin, user, '\n');
		finish = clock();
		//Ÿ���� ����

		//Ÿ���� �˻�
		for (int j = 0; j < context.size(); j += 2) {
			if (user.substr(j, 2).compare(context.substr(j, 2)) != 0) { //user, context�� Ȧ&¦���� �ѱ� ����(Ÿ��) �ϳ��� �ش�
				wrong++; //������Ÿ�� update
			}

		}

		rate = (float)(i + 1) * 100 / size; //����� update

		duration = (double)(finish - start) / CLOCKS_PER_SEC; //�ϳ� �Է� �ð�
		total += duration; //���� �ð� update

		count = context.size() / 2; //Ÿ��
		counts += count; //���� Ÿ�� update

		accuracy = 100.0 - (double)100 * wrong / counts; //������Ȯ�� update

		std::cout << "��� �ð�: " << duration << "��, "
				  << "���� Ÿ��:" << counts << "Ÿ, "
				  << "���� ��Ÿ��: " << wrong << "Ÿ, "
				  << "���� ��Ȯ��: " << accuracy << "%, "
				  << "���� �����: " << rate << "% �Դϴ�. " << endl;

	}
	///////Ÿ�ڿ�������
	speed = 60 * counts / total; //�ӵ�=�д� Ÿ��=(��üŸ��/��ü�ð�)*60

	///////����ǥ
	std::cout << endl;
	std::cout << "   ---------- ��ۿ��� ����---------" << endl;
	std::cout << "  |     �ӵ� : " << speed << "Ÿ/��         | " << endl;
	std::cout << "  |     �� ����ð� : " << total << "��         | " << endl;
	std::cout << "  |     ��Ȯ�� : " << accuracy << "%             | " << endl;
	std::cout << "  |     �� ��Ÿ�� : " << wrong << "��               | " << endl;
	std::cout << "  |     ���൵ : " << rate << "%              | " << endl;
	std::cout << "   --------------------------------" << endl;

	//////���� ���ڿ�ȭ
	string tmp = "��� Ÿ���� ���>> ";
	tmp.append("�ӵ�: " + to_string(speed) + "Ÿ/��, ");
	tmp.append("����ð�: " + to_string(total) + "��, ");
	tmp.append("��Ȯ��: " + to_string(accuracy) + "%, ");
	tmp.append("��Ÿ��: " + to_string(wrong) + "��\n");

	std::cout << " ��ۿ����� �����մϴ�...." << endl;

	return tmp;

}