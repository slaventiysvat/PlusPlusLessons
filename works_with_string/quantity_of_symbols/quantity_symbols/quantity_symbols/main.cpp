#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
using std::string;
using std::endl;
using std::cin;
using std::cout;
int main(void){
	string word;
	//������� ������� �� ������ 
	cout << "please, enter new word" << endl;
	cin >> word;
	int count = 0;
	auto size = word.size();
	cout << "size of word" << endl;
	const char* pword = word.c_str();//��������� �� ������ word
	for (int i = 0;i < word.size();i++){

		cout << pword[i] << endl;
		cout << "pointer" << endl;
	
	}

	for (int i = 0; i < word.size(); i++){

		cout << word.at(i) << endl;
		cout << "method at" << endl;//��������� ��� �� ��������� �� ��������� � word[], *word[],

	}

	for (auto tmp : word){
		
		cout << "number of letter" << " "<< count << "  " << tmp << endl;
		count = count + 1;
	}

	//������� ���������� ������ ����������

	
	cout << "please, enter new word" << endl;
	cin >> word;
	int a = 0;
	 count = 0;
	while (a < word.size()){
		if (ispunct(word.at(a))){
		
			count++;
		}

		a++;
	}

	cout << count << " " << "Quantity of symbols in entered string "<<endl;

	//���������� ��� ������� � ������ � ������� ��������
	cout << "please, enter new word fo change symbols in Up" << endl;
	cin >> word; 
	char cc;
	auto &c = cc;
	string tmp;
	for (int i = 0; i < word.size(); i++){
	
		c = toupper(word.at(i));
		word.at(i) = toupper(word.at(i));
		cout << "Rezult String first method" << " " << c << endl;
	}
	

	cout << "Rezult String secound method" << " " << word << endl;






	_getch();

	return 0;
}