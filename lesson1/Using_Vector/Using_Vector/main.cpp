#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
	vector<int> array(10);
	vector<int> array1(10,0);
	vector<vector<int>>  ivec(10, array1);
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++){

		for (int j = 0; j < 10; j++){

			cout << ivec[i][j] << " ";
			
		}
		cout << endl;
	}
	
	cout << "----------------------------------------------------------" << endl;
	_getch();
	return 0;
}