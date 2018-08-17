#include <iostream>
#include <string>
#include <conio.h>

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main(void){

	string word1;
	string word2;
	int count = 1;
	while (getline(cin, word1) && getline(cin, word2)){
	auto size_of_word1 = word1.size();
	auto size_of_word2 = word2.size();

	if (word1.empty()){

		cout << "String 1 is empty" << endl;
	}

	if (word2.empty()){

		cout << "String 2 is empty" << endl;
	}



	if (word1 == word2){

		cout << "String 1 the same as String 2" << endl;

	}
	if (word1 > word2){
		cout << "String 1 bigger then String 2" << endl;
		}
	
	if (word1 < word2){

				cout << "String 2 bigger then String 1" << endl;
			}
	cout << size_of_word2 <<" "<<"Size of the secound string "<< " "<<"  "  << size_of_word1 <<" "<< "Size of  the first string"<< endl;
	
	}

	_getch();
	return 0;
}

