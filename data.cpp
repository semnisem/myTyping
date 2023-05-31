#pragma once
#include "data.h"
#include<iostream>
#include<string>

void Dataset::edit() {

	std::cout << "*************** ������ ���� ��� ***************" << endl;
	std::cout << "   ------------ 0.�������� ------------" << endl;
	std::cout << "  | 1.�ܾ����   2.�ܾ����   3.�ܾ���� |" << endl;
	std::cout << "  | 4.�������   5.�������   6.������� |" << endl;
	std::cout << "  | 7.��ۻ���   8.��ۼ���   9.��ۻ��� |" << endl;
	std::cout << "   ------------------------------------" << endl;

	while (true) {

		std::cout << "\n������� ���� >> ";
		int choice;
		cin >> choice;

		switch (choice) {
		case(0): {
			std::cout << "************ ������ ���� ���� ************\n" << endl;
			return;
			break;
		}
		case(1): {
			get_word();
			show_word();
			break;
		}
		case(2): {
			modi_word();
			show_word();
			break;
		}
		case(3): {
			del_word();
			show_word();
			break;
		}
		case(4): {
			get_sentence();
			show_sentence();
			break;
		}
		case(5): {
			modi_sentence();
			show_sentence();
			break;
		}
		case(6): {
			del_sentence();
			show_sentence();
			break;
		}
		case(7): {
			get_essay();
			show_essay();
			break;
		}
		case(8): {
			modi_essay();
			show_essay();
			break;
		}
		case(9): {
			del_essay();
			show_essay();
			break;
		}
		default: {
			std::cout << "\n�߸��� �Է��̹Ƿ� ���α׷��� �����մϴ�" << endl;
			exit(0);
		}
		}
	}
}
//�ܾ� �������̹�ȯ
int Dataset::getWsize() {
	return wsize;
}
//���� ����ũ���ȯ
int Dataset::getSsize() {
	return ssize;
}
//���(����) ����ũ���ȯ
int Dataset::getEsize() {
	return esize;
}
//�ܾ� ����
void Dataset::get_word() {
	int tmp = 0;
	string s;
	std::cout << "�� ���� �ܾ �Է��Ͻðڽ��ϱ�? : ";
	cin >> tmp;
	std::cout << tmp << "�� �ܾ� �Է� >> ";
	//ó�� �Է��ϴ� ���
	if (wp == NULL) {
		wp = new string[tmp];
		for (int i = 0; i < tmp; i++) {
			cin >> wp[i];
		}
	}
	//�߰� �Է��ϴ� ���
	else {
		string* newp = new string[tmp + wsize];
		copy(wp, wp + wsize, newp);
		
		delete[] wp;
		wp = newp;
		newp = NULL;

		for (int i = 0; i < tmp; i++) {
			cin >> wp[wsize+i];
		}
	}
	wsize += tmp;
}
//���� ����
void Dataset::get_sentence() {
	int tmp;
	cout << "�� ���� ������ �Է��Ͻðڽ��ϱ�? : ";
	cin >> tmp;
	std::cout << tmp << "�� ���� �Է� >> ";
	//ó�� �Է��ϴ� ���
	if (sp == NULL) {
		sp = new string[tmp];
		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << i << "] ";
			getline(cin, sp[i], '\n');
		}
	}
	//�߰� �Է��ϴ� ���
	else {
		string* newp = new string[tmp + ssize];
		copy(sp, sp + ssize, newp);

		delete[] sp;
		sp = newp;
		newp = NULL;

		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << ssize+i << "] ";
			getline(cin, sp[ssize+i], '\n');
		}
	}
	ssize += tmp;
}
//��� ����
void Dataset::get_essay() {
	int tmp;
	cout << "�� ��(enter key ����)�� ������ �Է��Ͻðڽ��ϱ�? : ";
	cin >> tmp;
	std::cout << tmp << "�� ���� �Է� >> ";
	//ó�� �Է��ϴ� ���
	if (ep == NULL) {
		ep = new string[tmp];
		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << i << "] ";
			getline(cin, ep[i], '\n');
		}
	}
	//�߰� �Է��ϴ� ���
	else {
		string* newp = new string[tmp + esize];
		copy(ep, ep + esize, newp);

		delete[] ep;
		ep = newp;
		newp = NULL;

		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << esize + i << "] ";
			getline(cin, ep[esize + i], '\n');
		}
	}
	esize += tmp;
}
//��ü �ܾ� ���
void Dataset::show_word() {
	for (int i = 0; i < wsize; i++) {
		if (wp[i] != "")
			cout << wp[i] << " ";
		if (i == wsize - 1)
			std::cout << endl;
	}
}
//Ư�� �ܾ� ��ȯ
string Dataset::one_word(int i) {
	return wp[i];
}
//��ü ���� ���
void Dataset::show_sentence() {
	for (int i = 0; i < ssize; i++) {
		cout << "[" << i << "] ";
		std::cout << sp[i] << endl;
		if (i == ssize - 1)
			std::cout << endl;
	}
}
//Ư�� ���� ��ȯ
string Dataset::one_sentence(int i) {
	return sp[i];
}

//��ü ���� ���
void Dataset::show_essay() {
	for (int i = 0; i < esize; i++) {
		cout << "[" << i << "] ";
		std::cout << ep[i] << endl;
		if (i == esize - 1)
			std::cout << endl;
	}
}
//Ư�� ���� ��ȯ
string Dataset::one_essay(int i) {
	return ep[i];
}

//�ܾ� ����
void Dataset::modi_word() {
	std::cout << "������ �ܾ �Է��ϼ��� >> ";
	string word;
	cin >> word;
	for (int i = 0; i < wsize; i++) {
		if (wp[i].compare(word) == 0) {
			std::cout << "���� ��ǥ �ܾ �Է��ϼ��� >> ";
			cin >> word;
			wp[i] = word;
			std::cout << wp[i] << "�� �����Ǿ����ϴ�." << endl;
		}
	}
}
//���� ����
void Dataset::modi_sentence() {
	std::cout << "������ ������ġ�� �Է��ϼ��� >> ";
	int id = 0;
	cin >> id;
	cin.ignore();

	std::cout << "���� ��ǥ ������ �Է��ϼ��� >> ";
	string sentence;
	getline(cin, sentence, '\n');
	sp[id] = sentence;
	std::cout <<"�� �����Ǿ����ϴ�." << endl;
}
//��� ����
void Dataset::modi_essay() {
	std::cout << "������ �����ġ�� �Է��ϼ��� >> ";
	int id = 0;
	cin >> id;
	cin.ignore();	

	std::cout << "���� ��ǥ ����� �Է��ϼ��� >> ";
	string essay;
	getline(cin, essay, '\n');
	ep[id] = essay;
	std::cout << "�� �����Ǿ����ϴ�." << endl;
}

//�ܾ� ����
void Dataset::del_word() {
	std::cout << "������ �ܾ �Է��ϼ��� >> ";
	string word;
	cin >> word;
	for (int i = 0; i < wsize; i++) {
		if (wp[i].compare(word) == 0) {
			wp[i] = "";
			std::cout << wp[i] << "���� �Ǿ����ϴ�." << endl;
		}
	}
}
//���� ����
void Dataset::del_sentence() {
	std::cout << "������ ������ġ�� �Է��ϼ��� >> ";
	int id = 0;
	cin >> id;

	sp[id] = "";
	std::cout << "�����Ǿ����ϴ�." << endl;

}
//���� ����
void Dataset::del_essay() {
	std::cout << "������ �����ġ�� �Է��ϼ��� >> ";
	int id = 0;
	cin >> id;

	ep[id] = "";
	std::cout << "�����Ǿ����ϴ�." << endl;
}