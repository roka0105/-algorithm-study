#include <iostream>
using namespace std;

void func2( int row,int col, int num)
{
	if ((row / num) % 3 == 1 && (col / num) % 3 == 1)
	{
		cout << " ";
	}
	else if(num == 1)
	{
		cout << "*";
	}
	else
	{
		func2(row, col, num / 3);
	}
}
int main()
{
	int number = 0;

	cin >> number;

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			func2(i, j, number);
		}
		cout << "\n";
	}
}