#include <iostream>
using namespace std;
#define MAX 9
#define MIN 7
#define Height 100
int real[MIN];
int arr[MAX];
bool func(int x,int sum,int count)
{
	bool flag = false;
	if (count == MIN && sum == 100)
		return true;
	else if (count == MIN)
		return false;
	for (int i = x; i < MAX; i++)
	{
		sum += arr[i];
		real[count] = arr[i];
		flag=func(x + 1, sum, count + 1);
		if (flag)
			return true;
		else
		{
			sum -= arr[i];
		}
	}
	return false;
}
void sort()
{
	int temp = 0;
	for (int i = 0; i < MIN; i++)
	{
		int min = real[i];
		for (int j = i; j < MIN; j++)
		{
			if (min > real[j])
			{
				min = real[j];
				temp = real[i];
				real[i] = real[j];
				real[j] = temp;
			}
		}
	}
}
int main()
{
	
	for (int i = 0; i < MAX; i++)
	{
		cin >> arr[i];
	}
	int sum = 0;
	func(0, sum, 0);
	sort();
	cout << endl<<endl;
	for (int i = 0; i < MIN; i++)
	{
		cout << real[i] << endl;
	}

}