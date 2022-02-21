

//스페이스바 구현 x

#include <iostream>				
#include <conio.h>				//get _ ch 구현 위해서
#include <Windows.h>			//시스템 클리어 - 키입력후

using namespace std;

class Input_Oneletter {		//한글자 삽입
private:
	int num;
public:
	Input_Oneletter(){}

	int get_num() { return num; }
	void set_num() {		//숫자 세팅
		num = _getch();
		//if (num == 32)
			//exit(1);
	}
	void print_num() {
		cout << num << endl;
	}
};

class Returnvalue {
private:
	int temp_value;
public:
	Returnvalue(){
		//Input_Oneletter* test = new Input_Oneletter;
		Input_Oneletter test;
		test.set_num();
		if (test.get_num() == 49)
			temp_value = 49;
		else if (test.get_num() == 50)
			temp_value = 50;
		else if (test.get_num() == 52)
			temp_value = 52;
		else if (test.get_num() == 53)
			temp_value = 53;
		else if (test.get_num() == 55)
			temp_value = 55;
		else if (test.get_num() == 56)
			temp_value = 56;
		else if (test.get_num() == 32)
			temp_value = 32;
		else
			temp_value = 0;
	}
	void printvalue() {
		cout << temp_value<<endl;
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

		for (int i = 0; i < 6; i++)
		{
			array[i] = s[i].get_value();
			if (s[i].get_value() == 32) {
				break;
			}
			if (array[i] == 55)
				thearray[0] = array[i];
			else if (array[i] == 56)
				thearray[1] = array[i];
			else if (array[i] == 52)
				thearray[2] = array[i];
			else if (array[i] == 53)
				thearray[3] = array[i];
			else if (array[i] == 49)
				thearray[4] = array[i];
			else if (array[i] == 50)
				thearray[5] = array[i];
			//else if (array[i] = 32)
				//exit(1);
		}
	}
	

	void accumulate() {

	}

	void print_array() {
		for (int i = 0; i < 6; i++)
		{
			cout << thearray[i] << "\t";
		}
		cout << endl;
	}

	int get_arraymember(int i) {
		return thearray[i];
	}
};



/////////////////////////////////////////
class Drawing_print//:public Saveinarray
{
public:
	int key;
	Drawing_print() {

		while (1) {
			Saveinarray* y = new Saveinarray();
			y->compair();
			cout << "========================" << endl;
			cout << "7  8		  "<<y->get_arraymember(0)<<"  "<<y->get_arraymember(1) << endl;
			cout << "4  5		  " << y->get_arraymember(2)<<"  " << y->get_arraymember(3) << endl;
			cout << "1  2		  " << y->get_arraymember(4)<<"  " << y->get_arraymember(5) << endl;
			cout << "========================" << endl;
			//system("cls");
		}
	}
};

class Compare {
private:

public:
};

int main() {

	// InkjetPrinter* inkpp = new InkjetPrinter("OfficeJet V40","HP",5,10);
	//Returnbool* real = new Returnbool();	//1 : 49	2 : 50	 4 : 52		5 : 53		7 : 55		8 : 56
	//real->printbool();
	//Saveinarray* y = new Saveinarray();
	//y->print_array();
	Drawing_print a;
}