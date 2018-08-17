#include <iostream>
#include <cstdlib>
#include <time.h>
#include "rrand_func.h"

int get_sum_elem_of_V(int Arr[], const int SIZE);
int output_array_to_user(int Arr[], const int SIZE);
int* get_rand_array(const int SIZE, int range_min, int range_max);
int main(void){ 
	//enum{SIZE=10};
		setlocale(LC_ALL, "Russian");
		const int SIZE = 10;
		int range_min = 10;
		int range_max = 50;
		int* Arr = get_rand_array(SIZE, range_min, range_max);
		output_array_to_user(Arr, SIZE);
	

	system("pause");
	delete[] Arr;
	return 0;
}

int* get_rand_array(const int SIZE, int range_min, int range_max){

	srand(static_cast<unsigned int>(time(NULL)));
	int a = 0;

	int* Arr = new int[SIZE];

	while (a < SIZE){

		Arr[a] = rrand(range_min, range_max);

		a = a + 1;
	}

	return Arr;
}

int get_sum_elem_of_V(int* Arr, const int SIZE){
	
	int a = 0;
	int Sum = 0;
	while (a < SIZE){

		 Sum = Sum + Arr[a];

		a = a + 1;
	}
	return  Sum;
}



int output_array_to_user(int* Arr, const int SIZE){

	int Summ = get_sum_elem_of_V(Arr, SIZE);

	std::cout << Summ << " " << "Summ elements of Array" << std::endl;

	std::cout << "Output random Array" << std::endl;

	for (int i = 0; i < SIZE; i++){

		std::cout << Arr[i] << " " << "Num "<< " " << i << " " <<" of Arr " << std::endl;

	}

	return 0;

}



