#pragma once
#include<string>
using namespace std;

class Dataset {
private:
	int wsize = 0; //각 데이터 개수
	int ssize = 0;
	int esize = 0;
	string* wp; //낱말 데이터 포인터
	string* sp; //짧은글 데이터 포인터
	string* ep; //긴글 데이터 포인터
public:
	void edit(); //데이터 관리 사용자 인터페이스

	int getWsize(); //데이터 개수 반환
	int getSsize();
	int getEsize();

	void get_word(); //데이터 삽입
	void get_sentence();
	void get_essay();

	void show_word(); //전체 낱말 데이터 출력
	string one_word(int i); //해당 인덱스의 낱말 반환
	void show_sentence(); //전체 문장 데이터 출력
	string one_sentence(int i); //해당 인덱스의 문장 반환
	void show_essay(); //전체 긴글 데이터 출력
	string one_essay(int i); //해당 인덱스의 긴글 반환

	void modi_word(); //데이터 수정
	void modi_sentence();
	void modi_essay();

	void del_word(); //데이터 삭제
	void del_sentence();
	void del_essay();
};