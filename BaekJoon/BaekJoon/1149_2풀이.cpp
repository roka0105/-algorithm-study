#include <iostream>
using namespace std;
#define MAX 1001
int N = 0;
int arr[MAX][3] = { {0,0}, };
int cost[MAX][3] = { {0,0}, };
int g_min = 10000000;

void func()
{


}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
			if (i != 0)
			{
				arr[i][0] = cost[i][0] + min(arr[i-1][1], arr[i-1][2]);
				arr[i][1] = cost[i][1] + min(arr[i-1][0], arr[i - 1][2]);
				arr[i][2] = cost[i][2] + min(arr[i - 1][0], arr[i - 1][1]);
			}
			else
			{
				arr[i][j] = cost[i][j];
			}
		}
	}
	g_min = min(arr[N - 1][0], arr[N - 1][1]);
	g_min = min(g_min, arr[N - 1][2]);
	cout << g_min << '\n';
}