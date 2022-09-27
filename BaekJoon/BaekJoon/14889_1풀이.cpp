#include <iostream>
#include <vector>
using namespace std;
#define MAX 20
int N = 0;
int S[MAX][MAX] = { 0, };
int startnum[MAX / 2] = { -1,};
int linknum[MAX / 2] = { -1 };
int g_min = 101;

void func(int cnt)
{
	int sum = 0;
	bool flag = false;
	if (cnt == N / 2)
	{
		int start = 0;
		int link = 0;
		int x = 0;
		int y = 0;
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			flag = false;
			for (int j = 0; j < N / 2; j++)
			{
				if (startnum[j] == i)
				{
					for (int k = j + 1; k < N / 2; k++)
					{
						x = startnum[j];
						y = startnum[k];
						start += (S[x][y] + S[y][x]);
					}

					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				linknum[count++] = i;
			}
		}

		for (int j = 0; j < N / 2 - 1; j++)
		{
			for (int k = j + 1; k < N / 2; k++)
			{
				x = linknum[j];
				y = linknum[k];
				link += (S[x][y] + S[y][x]);
			}
		}
		sum = abs(start - link);
		if (g_min > sum)
			g_min = sum;
		return;
	}

	for (int i = cnt; i < N; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (startnum[j] == i&&startnum[0]!=-1)
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			startnum[cnt] = i;
			func(cnt + 1);
			startnum[cnt] = -1;
		}

	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}
	func(0);
	cout << g_min << '\n';
}