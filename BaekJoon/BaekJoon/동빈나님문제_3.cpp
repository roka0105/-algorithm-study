#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int N = 0;
int cost[MAX] = { 0 };
int main()
{
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
		if (cost[i] > max)
			max = cost[i];
	}
	sort(cost, cost + N, greater<int>());
	int cnt = 0;
	int result = 0;
	for (int i = cnt; i < N; i++)
	{
		cnt = 1;
		for (int j = i + 1; j <= N; j++)
		{
			if (cnt == cost[i])
			{
				result++;
				i += (cnt-1);
				break;
			}
			if (cost[i] >= cost[j])
			{
				cnt++;
			}
		}
	}
}