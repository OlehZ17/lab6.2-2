#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>


using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;

}
int IFirst(int* a, const int size, int& min, int i)
{
	if (a[i] % 2 != 0)
	{
		min = a[i]; 
		return i; 
	} 

	if (i < size - 1)
		return IFirst(a, size, min, i + 1);
	else
		return -1;
}
int Min(int* a, const int size, int min, int i)
{
	if (a[i] < min && a[i] % 2 != 0)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, min, i + 1);
	else
		return min;
}

int main()
{
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	const int n = 5;
	int a[n];
	int Low = -10;
	int High = 100;

	Create(a, n, Low, High);
	Print(a, n);

	int min; 
	int imin = IFirst(a, n, min, 0);
	if (imin == -1)
		cerr << "немаЇ елемент≥в, €к≥ задовольн€ють умов≥" << endl;
	else
		cout << "min = " << Min(a, n, min, imin + 1) << endl;
	return 0;
	
}

