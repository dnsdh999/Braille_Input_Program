
#include <iostream>				
#include <conio.h>				//get _ ch 구현 위해서
#include <Windows.h>			//시스템 클리어 - 키입력후
#include <string>
#include <fstream> 
#include <time.h>
#pragma warning(disable: 4996)

int confirmback = 0;			//백스페이스 관련

int ninetytwo = 0;				//전체 출력(그만입력)
int checkthing = 0;				//스페이스시 모든 배열을 0으로 채우는데 관련하는 전역변수
///////////////////////////////////////쓰이는 키에대한 전역 변수
int turnon49 = 0;
int turnon50 = 0;
int turnon52 = 0;
int turnon53 = 0;
int turnon55 = 0;
int turnon56 = 0;
int turnon32 = 0;
////////////////////////////////////////  출력에 관련하는 변수

char allletter[1000] = { 0 };
int counthow = 0;

using namespace std;

int confirmspace = 0;						//32
int confirm = 0;				//92

//많이 사용이되는 gotoxy 함수 정의
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };   //x, y 좌표 설정
			//coord는 위치를 저장하는 구조체,
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //커서 설정
			//커서 위치 변경하는 함수,콘솔창핸들,pos위치로 이동하라는 뜻.
}
//콘솔 내 커서 좌표따기


void beep() {
	cout << "\a"; // 시스템 비트 사운드(삑) 발생
}

class Input_Oneletter {		//한글자 삽입
private:
	int num;
public:
	Input_Oneletter() {}

	int get_num() { return num; }		//숫자 받아오기 위함
	void set_num() {		//숫자 세팅

		num = _getch();		//한글자를 받음
		if (num == 27)
			exit(1);
		else if (num == 32) {		//스페이스
			turnon32 = 1;
			checkthing = 1;
			confirmspace = 1;
		}
		else if (num == 92) {		//출력
			ninetytwo = 1;
			confirm = 1;
		}
		else if (num == 49) {		//숫자 패드 1
			turnon49 = 1;
		}
		else if (num == 50) {		//숫자 패드 2
			turnon50 = 1;
		}
		else if (num == 52) {		//숫자 패드 4
			turnon52 = 1;
		}		
		else if	(num == 53) {		//숫자 패드 5
			turnon53 = 1;
		}
		else if (num == 55) {		//숫자 패드 7
			turnon55 = 1;
		}
		else if (num == 56) {		//숫자 패드 8
			turnon56 = 1;
		}
		else if (num == 8) {		//백스페이스
			counthow = counthow - 1;
			confirmback = 1;
			if (counthow < 0) {
				counthow = 0;
			}
		}
		else {
			turnon32 = 1;
			checkthing = 1;
			confirmspace = 1;
		}
	}
};



string printar[3][2] = { { "○","○" },	
						{ "○","○" },
						{ "○","○" }
};

class Returnvalue {
private:
	int temp_value;
public:
	Returnvalue() {
		Input_Oneletter test;
		if ((checkthing == 0) && (ninetytwo == 0 || ninetytwo == 2)) {	//checkthing = 스페이스	//ninetytwo = 0일때 문자모드, ninetytwo = 2일때 숫자모드

			test.set_num();		//1개의 글자를 받아옴

			if (turnon49 == 1) {
				printar[2][0] = "●";	//눌렸을때 배열에 넣음.
				system("cls");
			}
			else if (turnon50 == 1) {
				printar[2][1] = "●";
				system("cls");
			}
			else if (turnon52 == 1) {
				printar[1][0] = "●";
				system("cls");
			}
			else if (turnon53 == 1) {
				printar[1][1] = "●";
				system("cls");
			}
			else if (turnon55 == 1) {
				printar[0][0] = "●";
				system("cls");
			}
			else if (turnon56 == 1) {
				printar[0][1] = "●";
				system("cls");
			}
			else if (turnon32 == 1){
				system("cls");
			}
			else if (confirmback == 1) {			//백스페이스 눌렸을때
				cout << "입력한 글자가 하나 줄었습니다." << endl;
			}

			if ((confirmspace == 0)&&(confirm == 0)&&(confirmback == 0)) {	//백스페이스,스페이스,출력 누르기 전까지 출력.
				cout << "┌───────────────────┐\n│\t\t    │" << endl;
				for (int i = 0; i < 3; i++) {
					cout << "│";
					for (int j = 0; j < 2; j++)
					{
						if (j == 0)cout << "\t";
						cout << printar[i][j] << "  ";
						if (j == 1)cout << "    │";
					}
					cout << endl;
				}
				cout << "│\t\t    │\n└───────────────────┘\n";
			}
			if (confirmback == 1) {		//백스페이스 눌렸을때
				cout << "입력한 문자가 하나 줄어듭니다." << endl;
				confirmback = 0; 
				cout << "\n입력한 문장 : ";
				for (int i = 0; i < counthow; i++)
				{
					cout << allletter[i];
				}
				cout << endl;
				cout << endl;
			}
			//까지 프린트

			turnon55 = 0;				turnon56 = 0;		//입력받은 후에 숫자를 다시받아야하기때문에 0으로 초기화
			turnon52 = 0;				turnon53 = 0;
			turnon49 = 0;				turnon50 = 0;


			if (test.get_num() == 49) {
				temp_value = 49;
			}
			else if (test.get_num() == 50) {
				temp_value = 50;
			}
			else if (test.get_num() == 52) {
				temp_value = 52;
			}
			else if (test.get_num() == 53) {
				temp_value = 53;
			}
			else if (test.get_num() == 55) {
				temp_value = 55;
			}
			else if (test.get_num() == 56) {
				temp_value = 56;
			}
			else {
				temp_value = 0;
			}
			//값을 받아옴
		}
	}
	
	int get_value() {
		return temp_value;
	}
};

class Saveinarray {
private:
	Returnvalue* s;
protected:
	int array[6];
	int thearray[6];
public:
	Saveinarray() {}

	void compair() {

		s = new Returnvalue[6];		//위의 클래스 6개 생성.
		confirmspace = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++)
			{
				printar[i][j] = "○";
			}
		}//입력안된 공백 상태로 초기화

		for (int i = 0; i < 6; i++)
		{

			array[i] = s[i].get_value();		//키를 눌렀을때 바로 배열에 저장됨. 그러므로 올바른 키 출력을 위해선 새로운 배열에 받아야함.

			if (array[i] == 55)
				thearray[0] = 1;
			else if (array[i] == 56)
				thearray[1] = 1;
			else if (array[i] == 52)
				thearray[2] = 1;
			else if (array[i] == 53)
				thearray[3] = 1;
			else if (array[i] == 49) 
				thearray[4] = 1;
			else if (array[i] == 50)
				thearray[5] = 1;
		}

	}

	int get_arraymember(int i) {
		return thearray[i];			//받은 배열의 멤버 리턴
	}
};

void intro() {
	cout << "점자 번역 프로그램 입니다." << endl;
	cout << "남윤오, 송영선 20200211~20200219" << endl;
	cout << "키는 7,8,4,5,1,2를 사용합니다." << endl;
	cout << "점자를 입력하면 스페이스를 입력합니다" << endl;
	cout << "출력은 '\'를 사용합니다." << endl;
	cout << "입력한 글자를 지우려면 backspace를 사용하세요" << endl;
	cout << "모두 입력한 뒤 저장시에는 yes를 누르세요" << endl;
	cout << "아무 키를 누르면 시작합니다." << endl;
	_getch();
	system("cls");
	cout << "========================" << endl;
	cout << "         ○  ○		 " << endl;
	cout << "         ○  ○		 " << endl;
	cout << "         ○  ○		 " << endl;
	cout << "========================" << endl<<endl<<endl;
	cout << "위에서 부터 7,8,4,5,1,2" << endl;
	cout << "키를 입력하면 바로 시작됩니다." << endl;
}



class Drawing_print //: public Saveinarray  
{
public:
	int key;
	Drawing_print() {
		intro();

		while (ninetytwo == 0 || ninetytwo == 2) {
			while (ninetytwo == 0) {

				Saveinarray* y = new Saveinarray();			//세이브인어레이 동적생성

				checkthing = 0;

				y->compair();		//함수호출

				int a = y->get_arraymember(0);
				int b = y->get_arraymember(1);
				int c = y->get_arraymember(2);
				int d = y->get_arraymember(3);
				int e = y->get_arraymember(4);
				int f = y->get_arraymember(5);

				//입력받은 배열 검사 과정
				if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'a' << endl;
					allletter[counthow] = 'a'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'b' << endl;
					allletter[counthow] = 'b'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'c' << endl;
					allletter[counthow] = 'c'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'd' << endl;
					allletter[counthow] = 'd'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'e' << endl;
					allletter[counthow] = 'e'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'f' << endl;
					allletter[counthow] = 'f'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'g' << endl;
					allletter[counthow] = 'g'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'h' << endl;
					allletter[counthow] = 'h'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'i' << endl;
					allletter[counthow] = 'i'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "입력된 문자 : " << 'j' << endl;
					allletter[counthow] = 'j'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'k' << endl;
					allletter[counthow] = 'k'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'l' << endl;
					allletter[counthow] = 'l'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'm' << endl;
					allletter[counthow] = 'm'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'n' << endl;
					allletter[counthow] = 'n'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'o' << endl;
					allletter[counthow] = 'o'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'p' << endl;
					allletter[counthow] = 'p'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'q' << endl;
					allletter[counthow] = 'q'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 'r' << endl;
					allletter[counthow] = 'r'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 's' << endl;
					allletter[counthow] = 's'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "입력된 문자 : " << 't' << endl;
					allletter[counthow] = 't'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {
					cout << endl << "입력된 문자 : " << 'u' << endl;
					allletter[counthow] = 'u'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 1 && f == 1) {
					cout << endl << "입력된 문자 : " << 'v' << endl;
					allletter[counthow] = 'v'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 1) {
					cout << endl << "입력된 문자 : " << 'w' << endl;
					allletter[counthow] = 'w'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 1 && f == 1) {
					cout << endl << "입력된 문자 : " << 'x' << endl;
					allletter[counthow] = 'x'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1) {
					cout << endl << "입력된 문자 : " << 'y' << endl;
					allletter[counthow] = 'y'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 1 && f == 1) {

					cout << endl << "입력된 문자 : " << 'z' << endl;
					allletter[counthow] = 'z'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {		//스페이스 - 띄움
					cout << endl << "스페이스 입력됨" << endl;
					beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {		//스페이스 - 띄움
					cout << endl << "줄바꿈 입력됨" << endl;
					beep();
					allletter[counthow] = '\n'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1) {
					cout << "숫자 모드로 전환됩니다." << endl;
					ninetytwo = 2;
				}
				else {
					cout << endl << "등록되지 않은 문자입니다." << endl;
				}


				cout << "\n입력한 문장 : \n";
				for (int i = 0; i < counthow; i++)
				{
					cout << allletter[i];
				}
				cout << endl;
				cout << endl;
			}
			while (ninetytwo == 2) {

				Saveinarray* y = new Saveinarray();

				checkthing = 0;

				y->compair();

				int a = y->get_arraymember(0);
				int b = y->get_arraymember(1);
				int c = y->get_arraymember(2);
				int d = y->get_arraymember(3);
				int e = y->get_arraymember(4);
				int f = y->get_arraymember(5);

				if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '1' << endl;
					allletter[counthow] = '1'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '2' << endl;
					allletter[counthow] = '2'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '3' << endl;
					allletter[counthow] = '3'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 0 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '4' << endl;
					allletter[counthow] = '4'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '5' << endl;
					allletter[counthow] = '5'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '6' << endl;
					allletter[counthow] = '6'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '7' << endl;
					allletter[counthow] = '7'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '8' << endl;
					allletter[counthow] = '8'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '9' << endl;
					allletter[counthow] = '9'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "입력된 숫자 : " << '0' << endl;
					allletter[counthow] = '0'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1)
				{
					cout << "문자 모드로 전환합니다." << endl;
					ninetytwo = 0;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {		//스페이스 - 띄움
					cout << endl << "스페이스 입력됨" << endl;
					beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {		//스페이스 - 띄움
					cout << endl << "줄바꿈 입력됨" << endl;
					beep();
					allletter[counthow] = '\n'; beep();
					counthow = counthow + 1;
				}


				cout << "\n입력한 문장 : \n";
				for (int i = 0; i < counthow; i++)
				{
					cout << allletter[i];
				}
				cout << endl;
				cout << endl;
			}
		}
		system("cls");
		cout << "입력된 전체문장 : \n";
		for (int i = 0; i < counthow; i++)
		{
			cout << allletter[i];
		}
		cout << endl;
	}
};



class Allsave {
public:
	Allsave() {}
	int allsavef() {
		string savechoice;
		cout << "입력한 문장을 저장하시겠습니까? 저장하려면 yes입력" << endl;
		getline(cin, savechoice);
		if (savechoice == "yes") {
			const char* File = "c:\\temp\\jeomja.txt";
			fstream fout(File, ios::out | ios::app); // 쓰기 모드로 파일 열기
			if (!fout) { // 열기 실패 검사
				cout << File << " 열기 오류";
				return 0;
			}

			time_t t = time(NULL);
			struct tm tm = *localtime(&t);

			printf("saved time: %d-%d-%d %d:%d:%d\n",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour, tm.tm_min, tm.tm_sec);
			fout << "저장된 시간 : " << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << "-" <<
				tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;

			// 파일 쓰기
			//time(fout,"c:\\temp\\jeomja.txt");
			for (int i = 0; i < counthow; i++)
			{
				fout << allletter[i] ; //  쓰기
			}
			fout << "\n" << endl;
			fout.close(); // 파일 닫기
			cout << "성공적으로 저장완료!" << endl;
		}
	}
};





int main() {
	Drawing_print a;
	Allsave* o = new Allsave();
	o->allsavef();
}
