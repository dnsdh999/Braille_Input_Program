

//스페이스바 구현 x

#include <iostream>				
#include <conio.h>				//get _ ch 구현 위해서
#include <Windows.h>			//시스템 클리어 - 키입력후
#include <string>

int ninetytwo = 0;
int checkthing = 0;

int turnon49 = 0;
int turnon50 = 0;
int turnon52 = 0;
int turnon53 = 0;
int turnon55 = 0;
int turnon56 = 0;

int countcount = 0;

using namespace std;

class Input_Oneletter {		//한글자 삽입
private:
	int num;
public:
	Input_Oneletter(){}

	int get_num() { return num; }
	void set_num() {		//숫자 세팅
		
		num = _getch();
		if (num == 27)
			exit(1);
		else if (num == 32) {
			checkthing = 1;
		}
		else if (num == 92) {
			ninetytwo = 1;
		}
		else if (num == 49) {
			turnon49 = 1;
			countcount++;
		}
		else if (num == 50) {
			turnon50 = 1;
			countcount++;
		}
		else if (num == 52) {
			turnon52 = 1;
			countcount++;
		}
		else if (num == 53) {
			turnon53 = 1;
			countcount++;
		}
		else if (num == 55) {
			turnon55 = 1;
			countcount++;
		}
		else if (num == 56) {
			turnon56 = 1;
			countcount++;
		}
	}
	void print_num() {
		cout << num << endl;
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

		if ((checkthing == 0)&&(ninetytwo == 0)) {
			if (countcount != 0) {
				if (turnon49 == 1) {
					//cout << "5번 입력되었습니다." << endl;
					printar[2][0] = "●";
				}
				else if (turnon50 == 1) {
					//cout << "6번 입력되었습니다." << endl;
					printar[2][1] = "●";
				}
				else if (turnon52 == 1) {
					//cout << "3번 입력되었습니다." << endl;
					printar[1][0] = "●";
				}
				else if (turnon53 == 1) {
					//cout << "4번 입력되었습니다." << endl;
					printar[1][1] = "●";
				}
				else if (turnon55 == 1) {
					//cout << "1번 입력되었습니다." << endl;
					printar[0][0] = "●";
				}
				else if (turnon56 == 1) {
					//cout << "2번 입력되었습니다." << endl;
					printar[0][1] = "●";
				}

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 2; j++)
					{
						cout << i << "행" << j << "열 : " << printar[i][j] << "  ";
					}
				}
				cout << "\n";
				//cout << "========================" << endl;
				//cout << "    [0][0]  [0][1]		 " << endl;
				//cout << "    [1][0]  [1][1]		 " << endl;
				//cout << "    [2][0]  [2][1]		 " << endl;
				//cout << "========================" << endl;
				turnon55 = 0;				turnon56 = 0;
				turnon52 = 0;				turnon53 = 0;
				turnon49 = 0;				turnon50 = 0;
			}

			test.set_num();


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

		s = new Returnvalue[6];

		countcount = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++)
			{
				printar[i][j] = "○";
			}
		}

		for (int i = 0; i < 6; i++)
		{

			array[i] = s[i].get_value();

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
		return thearray[i];
	}



};

void intro() {
	cout << "점자 번역 프로그램 입니다." << endl;
	cout << "아무 키를 누르면 시작합니다." << endl;
	cout << "키는 7,8,4,5,1,2를 사용합니다." << endl;
	_getch();
	system("cls");
}

char allletter[1000] = {0};
int counthow = 0;
/////////////////////////////////////////
class Drawing_print : public Saveinarray  //:public Saveinarray
{
public:
	int key;
	Drawing_print() {
		intro();
		cout << "========================" << endl;
		cout << "         ○  ○		 "  << endl;
		cout << "         ○  ○		 "  << endl;
		cout << "         ○  ○		 "  << endl;
		cout << "========================" << endl;
		while (ninetytwo == 0) {
			
			Saveinarray* y = new Saveinarray();
			
			checkthing = 0;
			
			y->compair();

			int light[3][2] = {
				{y->get_arraymember(0),y->get_arraymember(1)},
				{y->get_arraymember(2),y->get_arraymember(3)},
				{y->get_arraymember(4),y->get_arraymember(5)}
			};
			

			//cout << "========================" << endl;
			//cout << "7  8		  "<<y->get_arraymember(0)<<"  "<<y->get_arraymember(1) << endl;
			//cout << "4  5		  " << y->get_arraymember(2)<<"  " << y->get_arraymember(3) << endl;
			//cout << "1  2		  " << y->get_arraymember(4)<<"  " << y->get_arraymember(5) << endl;
			//cout << "========================" << endl;

			int a = y->get_arraymember(0);
			int b = y->get_arraymember(1);
			int c = y->get_arraymember(2);
			int d = y->get_arraymember(3);
			int e = y->get_arraymember(4);
			int f = y->get_arraymember(5);
			

			if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
				cout <<"입력된 문자 : "<< 'a' << endl;
				allletter[counthow] = 'a';
			}
			else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
				cout << "NULL" << endl;
			}
			else {
				cout << 'b' << endl;
				allletter[counthow] = 'b';
			}
			counthow = counthow + 1;

		}
		for (int i = 0; i < counthow; i++)
		{
			cout << allletter[i];
		}
	}
};



int main() {
	Drawing_print a;
}