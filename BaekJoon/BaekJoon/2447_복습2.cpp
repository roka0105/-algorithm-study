#include <iostream>
using namespace std;
int N = 0;
void func(int col, int row, int num)
{
	if ((col / num) % 3 == 1 && (row / num) % 3 == 1)
	{
		cout << " ";
	}
	else if(num==1)
	{
		cout << "*";
	}
	else
	{
		func(col, row, num / 3);
	}

}
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			func(i, j, N);
		}
		cout << '\n';
	}
}