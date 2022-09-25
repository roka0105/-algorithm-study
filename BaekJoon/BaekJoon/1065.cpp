#include <iostream>
using namespace std;
#define MAX 1001
bool hansu(int number)
{
	int n = number;
	int arr[MAX];
	int count = 0;
	while (n != 0)
	{
		arr[count++] = n % 10;
		n = n / 10;
	}
	if (count == 1)
	{
		return true;
	}	
	else
	{
		int minus = arr[1] - arr[0];
		int flagcount = 0;
		for (int i = 0; i < count-1; i++)
		{
			if (minus == arr[i + 1] - arr[i])
			{
				++flagcount;
			}
		}
		if (flagcount == count-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	int number = 0;
	cin >> number;
	bool flag = false;
	int count = 0;
	for (int i = 1; i <= number; i++)
	{
		flag = hansu(i);
		if (flag == true)
		{
			++count;
		}
	}
	cout << count << endl;
}