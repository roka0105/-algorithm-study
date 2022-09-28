#include <iostream>
using namespace std;
#define MAX 15

int N = 0;
int TP[MAX][2] = { {0,0} };

int g_max = 0;

int func(int day)
{
	int num = 0;
	int r = 0;
	
	int t_max = TP[day][1];
	if (day + TP[day][0] > N)
		return 0;
	for (int i = day; i <= N; i += num)
	{
		int result[2] = { 0 };
		num = TP[i][0];
		if (i + num >= N)
			break;
		int num2 = i + num + TP[i + num][0];
	    if(num2 <=N)
		result[0] = t_max + TP[i + num][1];
		if (TP[i + num][0] != 1 && i + (num * 2) < N && i + (num * 2) + TP[i + (num * 2)][0] <= N)
		{
			result[1] = t_max + TP[i + (num * 2)][1];
		}
		if (result[0] != 0 || result[1] != 0)
		{
			t_max = max(result[0], result[1]);
			if (result[0] <= result[1])
				num = i + (num * 2);
		}
		
	}
	return t_max;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> TP[i][j];
		}
	}
	int tempmax = 0;
	for (int i = 1; i <= N; i++)
	{
		tempmax = func(i - 1);
		if (g_max < tempmax)
			g_max = tempmax;
	}
	cout << g_max << '\n';
	return 0;
}