
#include <iostream>				
#include <conio.h>				//get _ ch ���� ���ؼ�
#include <Windows.h>			//�ý��� Ŭ���� - Ű�Է���
#include <string>
#include <fstream> 
#include <time.h>
#pragma warning(disable: 4996)

int confirmback = 0;			//�齺���̽� ����

int ninetytwo = 0;				//��ü ���(�׸��Է�)
int checkthing = 0;				//�����̽��� ��� �迭�� 0���� ä��µ� �����ϴ� ��������
///////////////////////////////////////���̴� Ű������ ���� ����
int turnon49 = 0;
int turnon50 = 0;
int turnon52 = 0;
int turnon53 = 0;
int turnon55 = 0;
int turnon56 = 0;
int turnon32 = 0;
////////////////////////////////////////  ��¿� �����ϴ� ����

char allletter[1000] = { 0 };
int counthow = 0;

using namespace std;

int confirmspace = 0;						//32
int confirm = 0;				//92

//���� ����̵Ǵ� gotoxy �Լ� ����
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };   //x, y ��ǥ ����
			//coord�� ��ġ�� �����ϴ� ����ü,
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //Ŀ�� ����
			//Ŀ�� ��ġ �����ϴ� �Լ�,�ܼ�â�ڵ�,pos��ġ�� �̵��϶�� ��.
}
//�ܼ� �� Ŀ�� ��ǥ����


void beep() {
	cout << "\a"; // �ý��� ��Ʈ ����(��) �߻�
}

class Input_Oneletter {		//�ѱ��� ����
private:
	int num;
public:
	Input_Oneletter() {}

	int get_num() { return num; }		//���� �޾ƿ��� ����
	void set_num() {		//���� ����

		num = _getch();		//�ѱ��ڸ� ����
		if (num == 27)
			exit(1);
		else if (num == 32) {		//�����̽�
			turnon32 = 1;
			checkthing = 1;
			confirmspace = 1;
		}
		else if (num == 92) {		//���
			ninetytwo = 1;
			confirm = 1;
		}
		else if (num == 49) {		//���� �е� 1
			turnon49 = 1;
		}
		else if (num == 50) {		//���� �е� 2
			turnon50 = 1;
		}
		else if (num == 52) {		//���� �е� 4
			turnon52 = 1;
		}		
		else if	(num == 53) {		//���� �е� 5
			turnon53 = 1;
		}
		else if (num == 55) {		//���� �е� 7
			turnon55 = 1;
		}
		else if (num == 56) {		//���� �е� 8
			turnon56 = 1;
		}
		else if (num == 8) {		//�齺���̽�
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



string printar[3][2] = { { "��","��" },	
						{ "��","��" },
						{ "��","��" }
};

class Returnvalue {
private:
	int temp_value;
public:
	Returnvalue() {
		Input_Oneletter test;
		if ((checkthing == 0) && (ninetytwo == 0 || ninetytwo == 2)) {	//checkthing = �����̽�	//ninetytwo = 0�϶� ���ڸ��, ninetytwo = 2�϶� ���ڸ��

			test.set_num();		//1���� ���ڸ� �޾ƿ�

			if (turnon49 == 1) {
				printar[2][0] = "��";	//�������� �迭�� ����.
				system("cls");
			}
			else if (turnon50 == 1) {
				printar[2][1] = "��";
				system("cls");
			}
			else if (turnon52 == 1) {
				printar[1][0] = "��";
				system("cls");
			}
			else if (turnon53 == 1) {
				printar[1][1] = "��";
				system("cls");
			}
			else if (turnon55 == 1) {
				printar[0][0] = "��";
				system("cls");
			}
			else if (turnon56 == 1) {
				printar[0][1] = "��";
				system("cls");
			}
			else if (turnon32 == 1){
				system("cls");
			}
			else if (confirmback == 1) {			//�齺���̽� ��������
				cout << "�Է��� ���ڰ� �ϳ� �پ����ϴ�." << endl;
			}

			if ((confirmspace == 0)&&(confirm == 0)&&(confirmback == 0)) {	//�齺���̽�,�����̽�,��� ������ ������ ���.
				cout << "������������������������������������������\n��\t\t    ��" << endl;
				for (int i = 0; i < 3; i++) {
					cout << "��";
					for (int j = 0; j < 2; j++)
					{
						if (j == 0)cout << "\t";
						cout << printar[i][j] << "  ";
						if (j == 1)cout << "    ��";
					}
					cout << endl;
				}
				cout << "��\t\t    ��\n������������������������������������������\n";
			}
			if (confirmback == 1) {		//�齺���̽� ��������
				cout << "�Է��� ���ڰ� �ϳ� �پ��ϴ�." << endl;
				confirmback = 0; 
				cout << "\n�Է��� ���� : ";
				for (int i = 0; i < counthow; i++)
				{
					cout << allletter[i];
				}
				cout << endl;
				cout << endl;
			}
			//���� ����Ʈ

			turnon55 = 0;				turnon56 = 0;		//�Է¹��� �Ŀ� ���ڸ� �ٽù޾ƾ��ϱ⶧���� 0���� �ʱ�ȭ
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
			//���� �޾ƿ�
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

		s = new Returnvalue[6];		//���� Ŭ���� 6�� ����.
		confirmspace = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++)
			{
				printar[i][j] = "��";
			}
		}//�Է¾ȵ� ���� ���·� �ʱ�ȭ

		for (int i = 0; i < 6; i++)
		{

			array[i] = s[i].get_value();		//Ű�� �������� �ٷ� �迭�� �����. �׷��Ƿ� �ùٸ� Ű ����� ���ؼ� ���ο� �迭�� �޾ƾ���.

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
		return thearray[i];			//���� �迭�� ��� ����
	}
};

void intro() {
	cout << "���� ���� ���α׷� �Դϴ�." << endl;
	cout << "������, �ۿ��� 20200211~20200219" << endl;
	cout << "Ű�� 7,8,4,5,1,2�� ����մϴ�." << endl;
	cout << "���ڸ� �Է��ϸ� �����̽��� �Է��մϴ�" << endl;
	cout << "����� '\'�� ����մϴ�." << endl;
	cout << "�Է��� ���ڸ� ������� backspace�� ����ϼ���" << endl;
	cout << "��� �Է��� �� ����ÿ��� yes�� ��������" << endl;
	cout << "�ƹ� Ű�� ������ �����մϴ�." << endl;
	_getch();
	system("cls");
	cout << "========================" << endl;
	cout << "         ��  ��		 " << endl;
	cout << "         ��  ��		 " << endl;
	cout << "         ��  ��		 " << endl;
	cout << "========================" << endl<<endl<<endl;
	cout << "������ ���� 7,8,4,5,1,2" << endl;
	cout << "Ű�� �Է��ϸ� �ٷ� ���۵˴ϴ�." << endl;
}



class Drawing_print //: public Saveinarray  
{
public:
	int key;
	Drawing_print() {
		intro();

		while (ninetytwo == 0 || ninetytwo == 2) {
			while (ninetytwo == 0) {

				Saveinarray* y = new Saveinarray();			//���̺��ξ�� ��������

				checkthing = 0;

				y->compair();		//�Լ�ȣ��

				int a = y->get_arraymember(0);
				int b = y->get_arraymember(1);
				int c = y->get_arraymember(2);
				int d = y->get_arraymember(3);
				int e = y->get_arraymember(4);
				int f = y->get_arraymember(5);

				//�Է¹��� �迭 �˻� ����
				if (a == 1 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'a' << endl;
					allletter[counthow] = 'a'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'b' << endl;
					allletter[counthow] = 'b'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'c' << endl;
					allletter[counthow] = 'c'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'd' << endl;
					allletter[counthow] = 'd'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'e' << endl;
					allletter[counthow] = 'e'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'f' << endl;
					allletter[counthow] = 'f'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'g' << endl;
					allletter[counthow] = 'g'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'h' << endl;
					allletter[counthow] = 'h'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'i' << endl;
					allletter[counthow] = 'i'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'j' << endl;
					allletter[counthow] = 'j'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'k' << endl;
					allletter[counthow] = 'k'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'l' << endl;
					allletter[counthow] = 'l'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'm' << endl;
					allletter[counthow] = 'm'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'n' << endl;
					allletter[counthow] = 'n'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'o' << endl;
					allletter[counthow] = 'o'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'p' << endl;
					allletter[counthow] = 'p'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'q' << endl;
					allletter[counthow] = 'q'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 'r' << endl;
					allletter[counthow] = 'r'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 's' << endl;
					allletter[counthow] = 's'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0) {
					cout << endl << "�Էµ� ���� : " << 't' << endl;
					allletter[counthow] = 't'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {
					cout << endl << "�Էµ� ���� : " << 'u' << endl;
					allletter[counthow] = 'u'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 1 && d == 0 && e == 1 && f == 1) {
					cout << endl << "�Էµ� ���� : " << 'v' << endl;
					allletter[counthow] = 'v'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 1) {
					cout << endl << "�Էµ� ���� : " << 'w' << endl;
					allletter[counthow] = 'w'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 0 && e == 1 && f == 1) {
					cout << endl << "�Էµ� ���� : " << 'x' << endl;
					allletter[counthow] = 'x'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1) {
					cout << endl << "�Էµ� ���� : " << 'y' << endl;
					allletter[counthow] = 'y'; beep();
					counthow = counthow + 1;
				}
				else if (a == 1 && b == 0 && c == 0 && d == 1 && e == 1 && f == 1) {

					cout << endl << "�Էµ� ���� : " << 'z' << endl;
					allletter[counthow] = 'z'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {		//�����̽� - ���
					cout << endl << "�����̽� �Էµ�" << endl;
					beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {		//�����̽� - ���
					cout << endl << "�ٹٲ� �Էµ�" << endl;
					beep();
					allletter[counthow] = '\n'; beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1) {
					cout << "���� ���� ��ȯ�˴ϴ�." << endl;
					ninetytwo = 2;
				}
				else {
					cout << endl << "��ϵ��� ���� �����Դϴ�." << endl;
				}


				cout << "\n�Է��� ���� : \n";
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
					cout << endl << "�Էµ� ���� : " << '1' << endl;
					allletter[counthow] = '1'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '2' << endl;
					allletter[counthow] = '2'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 0 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '3' << endl;
					allletter[counthow] = '3'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 0 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '4' << endl;
					allletter[counthow] = '4'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '5' << endl;
					allletter[counthow] = '5'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '6' << endl;
					allletter[counthow] = '6'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '7' << endl;
					allletter[counthow] = '7'; beep();
					counthow = counthow + 1;
				}
				if (a == 1 && b == 0 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '8' << endl;
					allletter[counthow] = '8'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 1 && d == 0 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '9' << endl;
					allletter[counthow] = '9'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0)
				{
					cout << endl << "�Էµ� ���� : " << '0' << endl;
					allletter[counthow] = '0'; beep();
					counthow = counthow + 1;
				}
				if (a == 0 && b == 1 && c == 0 && d == 1 && e == 1 && f == 1)
				{
					cout << "���� ���� ��ȯ�մϴ�." << endl;
					ninetytwo = 0;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {		//�����̽� - ���
					cout << endl << "�����̽� �Էµ�" << endl;
					beep();
					counthow = counthow + 1;
				}
				else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 1 && f == 1) {		//�����̽� - ���
					cout << endl << "�ٹٲ� �Էµ�" << endl;
					beep();
					allletter[counthow] = '\n'; beep();
					counthow = counthow + 1;
				}


				cout << "\n�Է��� ���� : \n";
				for (int i = 0; i < counthow; i++)
				{
					cout << allletter[i];
				}
				cout << endl;
				cout << endl;
			}
		}
		system("cls");
		cout << "�Էµ� ��ü���� : \n";
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
		cout << "�Է��� ������ �����Ͻðڽ��ϱ�? �����Ϸ��� yes�Է�" << endl;
		getline(cin, savechoice);
		if (savechoice == "yes") {
			const char* File = "c:\\temp\\jeomja.txt";
			fstream fout(File, ios::out | ios::app); // ���� ���� ���� ����
			if (!fout) { // ���� ���� �˻�
				cout << File << " ���� ����";
				return 0;
			}

			time_t t = time(NULL);
			struct tm tm = *localtime(&t);

			printf("saved time: %d-%d-%d %d:%d:%d\n",
				tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
				tm.tm_hour, tm.tm_min, tm.tm_sec);
			fout << "����� �ð� : " << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << "-" <<
				tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;

			// ���� ����
			//time(fout,"c:\\temp\\jeomja.txt");
			for (int i = 0; i < counthow; i++)
			{
				fout << allletter[i] ; //  ����
			}
			fout << "\n" << endl;
			fout.close(); // ���� �ݱ�
			cout << "���������� ����Ϸ�!" << endl;
		}
	}
};





int main() {
	Drawing_print a;
	Allsave* o = new Allsave();
	o->allsavef();
}
