// «десь € тестирую программу 
//где € обьедин€ю строки и вывожу их на екран
#include <iostream>
#include <string>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void){

	string input_word;
	string output_word;
	int count;
	string space(" ");
	int a = 1;
	while (a==1){
	
		getline(cin, input_word);
		output_word = output_word + space + input_word;
		cout << output_word << endl; 
		//cout << "do you want to continue"<< " " << "a =1 or a = 0 "<< endl;

		//cin >> a;

	}



	return 0;
}