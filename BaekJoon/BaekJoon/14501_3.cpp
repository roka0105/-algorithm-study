#include <iostream>
using namespace std;
#define MAX 15
#define T 0
#define P 1

int N = 0;
int TP[MAX][2];
int dp[MAX] = { 0, };
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
	int t_max = 0;
	int range = 0;
	for (int i = 0; i <= N; i++)
	{
		range = TP[i][T];
		for (int j = i; j <= N; j++)
		{
			if (j + range <= N)
			{
				dp[j + range] = max(dp[j + range], dp[i] + TP[i][P]);
			}
		}
		t_max = max(t_max, dp[i]);
	}
	cout << t_max << '\n';
}