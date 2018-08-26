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
	
	struct infoArray{

	vector<int> vv1;
	vector<int> vv3;
	vector<int> vv5;
	vector<int> vv6;
	vector<int> vv7;

	};

	infoArray get_info;
	vector<int> v1(10, 5);
	vector<int> v2(120, 1);
	vector<int> v3(115, 3);
	vector<int> v4(15, 8);
	vector<int> v5(18, 9);
	get_info.vv1 = v1;
	get_info.vv3 = v2;
	get_info.vv5 = v3;
	get_info.vv6 = v4;
	get_info.vv7 = v5;
	infoArray *ptr;
	ptr = &get_info;
	vector<int> tmp;
	tmp = get_info.vv3;
		
	cout << "Size each field of struct " << " " << tmp.size() << endl;
	
	
	

	_getch();
	return 0;
}