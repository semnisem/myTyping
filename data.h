#pragma once
#include<string>
using namespace std;

class Dataset {
private:
	int wsize = 0; //�� ������ ����
	int ssize = 0;
	int esize = 0;
	string* wp; //���� ������ ������
	string* sp; //ª���� ������ ������
	string* ep; //��� ������ ������
public:
	void edit(); //������ ���� ����� �������̽�

	int getWsize(); //������ ���� ��ȯ
	int getSsize();
	int getEsize();

	void get_word(); //������ ����
	void get_sentence();
	void get_essay();

	void show_word(); //��ü ���� ������ ���
	string one_word(int i); //�ش� �ε����� ���� ��ȯ
	void show_sentence(); //��ü ���� ������ ���
	string one_sentence(int i); //�ش� �ε����� ���� ��ȯ
	void show_essay(); //��ü ��� ������ ���
	string one_essay(int i); //�ش� �ε����� ��� ��ȯ

	void modi_word(); //������ ����
	void modi_sentence();
	void modi_essay();

	void del_word(); //������ ����
	void del_sentence();
	void del_essay();
};