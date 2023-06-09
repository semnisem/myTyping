#include "data.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string word(Dataset& data) {

	std::cout << "************ 낱말 연습 시작 ************" << endl;
	clock_t start, finish; //시간 체크 위해서
	double duration; //단어당 시간
	double total = 0.0; //전체 시간
	double speed; //속도(한 음절당 시간)=(전체시간/전체단어 음절 수)


	int size = data.getWsize(); //전체단어 개수
	double rate; //진행률 = (현재인덱스+1)/전체단어개수
	int count = 0; //단어 타수 (타수 = size/2 (한글은2bytes이므로))
	int counts = 0; //누적 타수

	int wrong = 0; //누적 오타 수
	double accuracy; //누적정확도=100-100*(누적오타수/누적타수)

	for (int i = 0; i < size; i++) {

		//타이핑할 단어 출력
		while (data.one_word(i) == "") {
			i++;
		}
		string word = data.one_word(i);
		std::cout << word << ">> ";

		///예시에 맞게 타이핑
		start = clock();
		string user;
		cin >> user;
		finish = clock();
		//타이핑 종료

		//타이핑 검사
		for (int j = 0; j < word.size(); j+=2) {
			if (user.substr(j, 2).compare(word.substr(j, 2))!=0) { //user, word의 홀&짝수가 한글 음절(타수) 하나에 해당
				wrong++; //누적 오타 수 update
			}
			
		}
		rate = (float)(i + 1) * 100 / size; //진행률 update

		duration = (double)(finish - start) / CLOCKS_PER_SEC; //하나 입력 시간
		total += duration; //누적 시간 update

		count = word.size()/2; //타수
		counts += count; //누적 타수 update

		accuracy = 100.0 - (double)100*wrong / counts; //누적정확도 update

		std::cout <<"경과 시간: " << duration << "초, " 
			      <<"누적 타수:" << counts <<"타, "
			      <<"누적 오타수: " << wrong <<"타, "
			      <<"누적 정확도: " << accuracy<< "%, " 
			      <<"현재 진행률: " << rate << "% 입니다. " << endl;
	}
	///////타자연습종료
	speed = 60* counts / total; //속도=분당 타수=(전체타수/전체시간)*60

	///////성적표
	std::cout << endl;
	std::cout << "   ----------낱말연습 성적---------" << endl;
	std::cout << "  |     속도 : " << speed << "타/분            | " << endl;
	std::cout << "  |     총 경과시간 : " << total << "초         | " << endl;
	std::cout << "  |     정확도 : " << accuracy << "%             | " << endl;
	std::cout << "  |     총 오타수 : " << wrong << "개               | " << endl;
	std::cout << "  |     진행도 : " << rate << "%                 | " << endl;
	std::cout << "   --------------------------------" << endl;

	//////성적 문자열화
	string tmp = "단어타이핑 결과>> ";
    tmp.append("속도: "+to_string(speed) + "타/분, ");
	tmp.append("정확도: "+to_string(accuracy) + "%, ");
	tmp.append("오타수: " + to_string(wrong) + "개\n");

	std::cout << " 낱말연습을 종료합니다...." << endl;

	return tmp;
}
