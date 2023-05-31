//���
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//���� ����
void write(string record) {
	ofstream ofs("scores.txt", ios::app);
	if (!ofs) { //���� ���� ���н� ����ó��
		cerr << "!!!!����: ������ ������ ���߽��ϴ�!!!!!" << endl;
		return;
	}
	//Ŀ�� ����
	ofs.seekp(0);

	//���Ͽ� ��� ����
	ofs << record;

	//���Ͼ���ݱ�
	ofs.close();

	cout << " ��Ͼ��⸦ �Ϸ��߽��ϴ�!\n\n" << endl;
	return;
}

//���� �б�
void read() {
	ifstream ifs("scores.txt");
	if (!ifs) { //���� �б� ���н� ����ó��
		cout << "!!!!����: ������ ���� ���߽��ϴ�!!!!!" << endl;
		return;
	}
	std::cout << " [�������] " << endl;

	//���� ���� �о ���
	string record;
	int i = 0;
	while (!ifs.eof()) { //*�߿�: ������ ��� eof�� �ش�ȵ�
		getline(ifs, record);
		cout << record << endl;
	}
	
	//�����б�ݱ�
	ifs.close();

	cout << "\n\n" << endl;
	return;
}