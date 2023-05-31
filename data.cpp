#pragma once
#include "data.h"
#include<iostream>
#include<string>

void Dataset::edit() {

	std::cout << "*************** 데이터 편집 모드 ***************" << endl;
	std::cout << "   ------------ 0.편집종료 ------------" << endl;
	std::cout << "  | 1.단어삽입   2.단어수정   3.단어삭제 |" << endl;
	std::cout << "  | 4.문장삽입   5.문장수정   6.문장삭제 |" << endl;
	std::cout << "  | 7.긴글삽입   8.긴글수정   9.긴글삭제 |" << endl;
	std::cout << "   ------------------------------------" << endl;

	while (true) {

		std::cout << "\n편집모드 선택 >> ";
		int choice;
		cin >> choice;

		switch (choice) {
		case(0): {
			std::cout << "************ 데이터 편집 종료 ************\n" << endl;
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
			std::cout << "\n잘못된 입력이므로 프로그램을 종료합니다" << endl;
			exit(0);
		}
		}
	}
}
//단어 공간길이반환
int Dataset::getWsize() {
	return wsize;
}
//문장 공간크기반환
int Dataset::getSsize() {
	return ssize;
}
//긴글(문단) 공간크기반환
int Dataset::getEsize() {
	return esize;
}
//단어 삽입
void Dataset::get_word() {
	int tmp = 0;
	string s;
	std::cout << "몇 개의 단어를 입력하시겠습니까? : ";
	cin >> tmp;
	std::cout << tmp << "개 단어 입력 >> ";
	//처음 입력하는 경우
	if (wp == NULL) {
		wp = new string[tmp];
		for (int i = 0; i < tmp; i++) {
			cin >> wp[i];
		}
	}
	//추가 입력하는 경우
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
//문장 삽입
void Dataset::get_sentence() {
	int tmp;
	cout << "몇 개의 문장을 입력하시겠습니까? : ";
	cin >> tmp;
	std::cout << tmp << "개 문장 입력 >> ";
	//처음 입력하는 경우
	if (sp == NULL) {
		sp = new string[tmp];
		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << i << "] ";
			getline(cin, sp[i], '\n');
		}
	}
	//추가 입력하는 경우
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
//긴글 삽입
void Dataset::get_essay() {
	int tmp;
	cout << "몇 개(enter key 기준)의 문단을 입력하시겠습니까? : ";
	cin >> tmp;
	std::cout << tmp << "개 문단 입력 >> ";
	//처음 입력하는 경우
	if (ep == NULL) {
		ep = new string[tmp];
		cin.ignore();
		for (int i = 0; i < tmp; i++) {
			cout << "[" << i << "] ";
			getline(cin, ep[i], '\n');
		}
	}
	//추가 입력하는 경우
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
//전체 단어 출력
void Dataset::show_word() {
	for (int i = 0; i < wsize; i++) {
		if (wp[i] != "")
			cout << wp[i] << " ";
		if (i == wsize - 1)
			std::cout << endl;
	}
}
//특정 단어 반환
string Dataset::one_word(int i) {
	return wp[i];
}
//전체 문장 출력
void Dataset::show_sentence() {
	for (int i = 0; i < ssize; i++) {
		cout << "[" << i << "] ";
		std::cout << sp[i] << endl;
		if (i == ssize - 1)
			std::cout << endl;
	}
}
//특정 문장 반환
string Dataset::one_sentence(int i) {
	return sp[i];
}

//전체 문단 출력
void Dataset::show_essay() {
	for (int i = 0; i < esize; i++) {
		cout << "[" << i << "] ";
		std::cout << ep[i] << endl;
		if (i == esize - 1)
			std::cout << endl;
	}
}
//특정 문단 반환
string Dataset::one_essay(int i) {
	return ep[i];
}

//단어 수정
void Dataset::modi_word() {
	std::cout << "수정할 단어를 입력하세요 >> ";
	string word;
	cin >> word;
	for (int i = 0; i < wsize; i++) {
		if (wp[i].compare(word) == 0) {
			std::cout << "수정 목표 단어를 입력하세요 >> ";
			cin >> word;
			wp[i] = word;
			std::cout << wp[i] << "로 수정되었습니다." << endl;
		}
	}
}
//문장 수정
void Dataset::modi_sentence() {
	std::cout << "수정할 문장위치를 입력하세요 >> ";
	int id = 0;
	cin >> id;
	cin.ignore();

	std::cout << "수정 목표 문장을 입력하세요 >> ";
	string sentence;
	getline(cin, sentence, '\n');
	sp[id] = sentence;
	std::cout <<"로 수정되었습니다." << endl;
}
//긴글 수정
void Dataset::modi_essay() {
	std::cout << "수정할 긴글위치를 입력하세요 >> ";
	int id = 0;
	cin >> id;
	cin.ignore();	

	std::cout << "수정 목표 긴글을 입력하세요 >> ";
	string essay;
	getline(cin, essay, '\n');
	ep[id] = essay;
	std::cout << "로 수정되었습니다." << endl;
}

//단어 삭제
void Dataset::del_word() {
	std::cout << "삭제할 단어를 입력하세요 >> ";
	string word;
	cin >> word;
	for (int i = 0; i < wsize; i++) {
		if (wp[i].compare(word) == 0) {
			wp[i] = "";
			std::cout << wp[i] << "삭제 되었습니다." << endl;
		}
	}
}
//문장 삭제
void Dataset::del_sentence() {
	std::cout << "삭제할 문장위치를 입력하세요 >> ";
	int id = 0;
	cin >> id;

	sp[id] = "";
	std::cout << "삭제되었습니다." << endl;

}
//문단 삭제
void Dataset::del_essay() {
	std::cout << "삭제할 긴글위치를 입력하세요 >> ";
	int id = 0;
	cin >> id;

	ep[id] = "";
	std::cout << "삭제되었습니다." << endl;
}