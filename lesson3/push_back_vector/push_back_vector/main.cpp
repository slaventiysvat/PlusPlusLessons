#include <vector>
#include <iostream>
#include <string>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int func_cout(vector<string>);

int main(void){

	string word;
	vector<string> str;
	int num;
	int stop = -1;
	cout << "please enter your numbers" << endl;
	while (cin >> word){
		cout << "do you want to continue" << endl;
		cout << "number bigger than 0 - yes, if number < 0 - no.Number should be integer" << endl;
		cin >> stop;
		if (stop > 0){
		
			func_cout(str);
			break;
		
		}


		str.push_back(word);
	
	}



	return 0;
}

 int func_cout(vector<string> str){
	 cout << "members of string" << endl;
	 int M = str.size();//little optimization
	 for (int i = 0; i < M; i++){
	 
		 cout << str[i] << endl;
	 }
	 
}