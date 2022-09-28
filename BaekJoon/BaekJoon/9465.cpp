#include <iostream>
using namespace std;
#define COL 2
#define MAX 100000
int T = 0;
int N = 0;
int cost[COL][MAX] = { {0,0} };
int arr[COL][MAX] = { {0,0} };
int g_max = 0;
void bottomup()
{
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}

	arr[0][0] = cost[0][0];
	arr[1][0] = cost[1][0];
	arr[0][1] = cost[1][0] + cost[0][1];
	arr[1][1] = cost[0][0] + cost[1][1];

	for (int i = 2; i < N; i++)
	{
		arr[0][i] = cost[0][i] + max(arr[1][i - 1], arr[1][i - 2]);
		arr[1][i] = cost[1][i] + max(arr[0][i - 1], arr[0][i - 2]);
	}
	g_max = max(arr[0][N - 1], arr[1][N - 1]);

}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		bottomup();
		cout << g_max << '\n';
	}
}