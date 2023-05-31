//기록
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//파일 쓰기
void write(string record) {
	ofstream ofs("scores.txt", ios::app);
	if (!ofs) { //파일 생성 실패시 예외처리
		cerr << "!!!!에러: 파일을 만들지 못했습니다!!!!!" << endl;
		return;
	}
	//커서 지정
	ofs.seekp(0);

	//파일에 기록 쓰기
	ofs << record;

	//파일쓰기닫기
	ofs.close();

	cout << " 기록쓰기를 완료했습니다!\n\n" << endl;
	return;
}

//파일 읽기
void read() {
	ifstream ifs("scores.txt");
	if (!ifs) { //파일 읽기 실패시 예외처리
		cout << "!!!!에러: 파일을 읽지 못했습니다!!!!!" << endl;
		return;
	}
	std::cout << " [성적기록] " << endl;

	//파일 내용 읽어서 출력
	string record;
	int i = 0;
	while (!ifs.eof()) { //*중요: 공백인 경우 eof에 해당안됨
		getline(ifs, record);
		cout << record << endl;
	}
	
	//파일읽기닫기
	ifs.close();

	cout << "\n\n" << endl;
	return;
}