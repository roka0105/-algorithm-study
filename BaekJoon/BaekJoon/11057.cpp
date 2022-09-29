#include <iostream>
using namespace std;
#define ROW 10
#define COL 1000
#define MOD 10007

int N = 0;
unsigned long long dp[COL][ROW] = { {1,}, };
unsigned long long g_data[COL][ROW] = { 0,1,1,1,1,1,1,1,1,1 };

int main()
{
	cin >> N;
	unsigned long long t_max = 0;
	for (int i = 0; i < N; i++)
	{
		unsigned long long minus = (i == 0) ? 1 : t_max;
		for (int j = 0; j < ROW; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][ROW - 1] % MOD;
			}
			else
			{
				dp[i][j] = (dp[i][j - 1] + minus)%MOD;
				if (i != 0)
				{
					g_data[i][j] = minus;
					minus -= (g_data[i - 1][j] % MOD);
					g_data[j];
				}
				t_max += minus%MOD;
			}
		}
	}
	cout << dp[N - 1][ROW - 1] % MOD << '\n';
}