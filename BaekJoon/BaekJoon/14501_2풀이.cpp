#include <iostream>
using namespace std;
#define MAX 15

int arr[MAX][2] = { {0,0} };
int N = 0;
int g_max = 0;
int dp[MAX] = { 0 };
bool visit[MAX] = { false };

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}
	int t_max = 0;
	int range = 0;
	for (int i = 0; i <= N; i++)
	{
		range = arr[i][0];
		dp[i] = max(t_max, dp[i]);
		if (range + i <= N)
		{
			dp[i+ range] = max(dp[i+range], arr[i][1] + dp[i]);
		}
		t_max = max(t_max, dp[i]);
	}

	cout << t_max << '\n';
}