#include <iostream>
using namespace std;
void result(int num,int& sum)
{
	if (num == 0)
	{
		return;
	}
	sum += num % 10;
	result(num / 10, sum);
}
int main()
{
	int N = 0, M = 0;
	cin >> N;
	int sum = 0;
	bool find = false;
	for (int i = 1; i <= N; i++)
	{
		sum = i;
		result(i, sum);
		if (sum == N)
		{
			cout << i << endl;
			find = true;
			break;
		}
	}
	if (find == false)
	{
		cout << 0 << endl;
	}
}