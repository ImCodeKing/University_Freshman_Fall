#include <iostream>
#include <string>
using namespace std;
int main()
{
	int Array[3] = { 0 };
	int& Array1 = Array[5];
	int* Array2 = Array + 5;
	cout << Array1 << '\n' << *(Array2);
	return 0;
}

