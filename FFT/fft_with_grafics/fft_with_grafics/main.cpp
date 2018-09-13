
#include <iostream>
#include <math.h>
#include <vector>

double get_sinus_signal(vector<double> signal,int Fs, int Length, int f);

int main(void){

	//create new signal
	int Fs = 25;
	int Length = 50;
	int f = 5;
	vector<double> signal;
	get_sinus_signal(signal,Fs, Length,f)
		int a = 0;
	while (a < length){
	
		cout << signal.at(a) << endl;
	}

	return 0;
}

double get_sinus_signal(vector<double> signal, int Fs, int Length, int f){
	
	try //код, который может привести к ошибке, располагается тут
	{
		if (Fs > Length)
		{
			throw 1; //генерировать целое число 123
		}
		
	}
	catch (int i)//сюда передастся число 1
	{
		cout << "Error №" << i << " - Fs must be less than Length" << endl;
	}

	double T = 1 / Fs;
	//t = (0:L - 1)*T;взято из матлаба
	vector<double> t(Length);
	for (int i = 0; i < length; i++){
	
		t.push_back(i*T);

	}
	//vector<double> signal(Length);
	double a = 0;
	double pi = 3.1415926535897;
	while (a < Length){
		
		x = sin(2*pi*f*t.at(a))
		signal.push_back(x);
	
	a++;
	}

	
}