#include <iostream>
#include <math.h>
#include <vector>
#include <conio.h>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
//
double get_sig(double x,double f,double t);

int main(void){

	//create new signal
	// Ќачальные параметры сигнала
	double Fs = 50;
	int Length = 50;
	double f = 5;
	double x = 0;
	////формируем сигнал
	vector<double> signal;
	vector<double> t;
	double T = 1 / Fs;
	double value = 0;
	for (int i = 0; i < Length; i++){
		 t.push_back(i*T);
		cout << t.at(i) << endl;
	}

	int a = 0;
	while (a < Length){
			
			value = get_sig(x, f, t.at(a));
			signal.push_back(value);

		a++;
	}
	a = 0;
	while (a < Length){

		cout << signal.at(a) << endl;
		a = a + 1;
	}
	_getch();
	return 0;
}

double get_sig(double x, double f,double t){

	double pi = 3.1415926535897;
	x = sin(2 * pi*f*t);
	return x;
}