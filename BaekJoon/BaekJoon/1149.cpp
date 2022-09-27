#include <iostream>
using namespace std;

#define COLOR 3
#define MAX 1001
int cost[MAX][COLOR];
int house[MAX] = { -1 };
int N = 0;
int g_min = 10000000;
void func(int color, int cnt)
{
	if (cnt == N)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += cost[i][house[i]];
		}
		if (g_min > sum)
			g_min = sum;
		return;
	}

	for (int j = 0; j < COLOR; j++)
	{
		if (j == color && house[0] != -1)
			continue;
		house[cnt] = j;
		func(j, cnt + 1);
	}

}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < COLOR; j++)
		{
			cin >> cost[i][j];
		}
	}
	func(0, 0);
	cout << g_min << '\n';
}