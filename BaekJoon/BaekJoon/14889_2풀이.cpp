#include <iostream>
#include <vector>
using namespace std;
#define MAX 20
bool check[MAX];
int g_min = 10000000;
int N = 0;
int S[MAX][MAX] = { 0, };

void func(int index, int cnt)
{
	vector<int> startidx;
	vector<int> linkidx;
	int start = 0;
	int link = 0;
	if (cnt == N / 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (check[i] == true)
			{
				startidx.push_back(i);
			}
			else
			{
				linkidx.push_back(i);
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				start += S[startidx[i]][startidx[j]];
				link += S[linkidx[i]][linkidx[j]];
			}
		}
		int m = abs(start - link);
		if (g_min > m)
		{
			g_min = m;
		}
		return;
	}
	for (int i = index; i < N; i++)
	{
		if (check[i] == true)
			continue;
		else
		{
			check[i] = true;
			func(i, cnt + 1);
			check[i] = false;
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
	func(0, 0);

	cout << g_min << '\n';
}