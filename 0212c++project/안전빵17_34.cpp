#include <iostream>
#include <conio.h>

using namespace std;

class Input_Oneletter {
private:
	int num;
public:
	Input_Oneletter(){}

	int get_num() { return num; }
	void set_num() {
		num = _getch();
	}
	void print_num() {
		cout << num << endl;
	}
};

class Returnbool {
private:
	bool yesorno;
public:
	Returnbool(){
		//Input_Oneletter* test = new Input_Oneletter;
		Input_Oneletter test;
		test.set_num();
		if (test.get_num() == 49)
			yesorno = 1;
		else if (test.get_num() == 50)
			yesorno = 1;
		else if (test.get_num() == 52)
			yesorno = 1;
		else if (test.get_num() == 53)
			yesorno = 1;
		else if (test.get_num() == 55)
			yesorno = 1;
		else if (test.get_num() == 56)
			yesorno = 1;
		else
			yesorno = 0;
	}
	void printbool() {
		cout << yesorno<<endl;
	}
	bool get_bool() {
		return yesorno;
	}
};

class Saveinarray {
private:
	Returnbool *s;
protected:
	int array[6];
public:
	Saveinarray() {
		s = new Returnbool[6];
		array[0] = s[0].get_bool(); array[1] = s[1].get_bool();
		array[2] = s[2].get_bool(); array[3] = s[3].get_bool();
		array[4] = s[4].get_bool(); array[5] = s[5].get_bool();
	}

	void print_array() {
		for (int i = 0; i < 6; i++)
		{
			cout << array[i] << "\t";
		}
		cout << endl;
	}
};
/////////////////////////////////////////
class Drawing_print :public Saveinarray{
public:
	Drawing_print() {
		
		
		
		cout << "========================"<<endl;
		cout << "7  8		  <<array[]<< array[]" << endl;
		cout << "4  5		  <<%d  %d" << endl;
		cout << "1  2		  <<%d  %d" << endl;
		cout << "========================" << endl;
		
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
	Saveinarray* y = new Saveinarray();
	y->print_array();
	Drawing_print a;
}