#include <iostream>
using namespace std;
#define MAX 12
#define OPMAX 4
int N = 0;
int arr[MAX];
int opcnt[OPMAX];
bool opcheck[MAX - 1] = { false, };
int op[MAX - 1] = { 0, };
int g_min = 1000000000;
int g_max = -1000000000;
void func(int cnt, int sum)
{
	if (cnt == N)
	{
		if (sum > g_max)
		{
			g_max = sum;
		}
		if (sum < g_min)
		{
			g_min = sum;
		}
		return;
	}
	int num = sum;
	for (int i = 0; i < N - 1; i++)
	{
		if (opcheck[i] == false)
		{
			opcheck[i] = true;
			switch (op[i])
			{
			case 0:
				sum += arr[cnt];
				break;
			case 1:
				sum -= arr[cnt];
				break;
			case 2:
				sum *= arr[cnt];
				break;
			case 3:
				sum /= arr[cnt];
				break;
			}

			func(cnt + 1, sum);
			sum = num;
			opcheck[i] = false;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int _max = N - 1;
	int index = 0;
	// + , - , * , /
	for (int i = 0; i < OPMAX; i++)
	{
		do
		{
			cin >> opcnt[i];
		} while (opcnt[i] > _max);
		for (int j = 0; j < opcnt[i]; j++)
		{
			op[index++] = i;
		}
		_max -= opcnt[i];
	}
	func(1, arr[0]);
	cout << g_max << '\n';
	cout << g_min << '\n';
	
}