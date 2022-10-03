#include <iostream>
#include <vector>
using namespace std;
#define MAX 21
#define NMAX 101
vector<int> person[MAX];
vector<bool> visited;
int N = 0;
int g_min = NMAX;
vector<int> start;
vector<int> link;
void func(int index,int cnt)
{
	if (cnt == N / 2)
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i])
			{
				link.push_back(i);
			}
			else
			{
				start.push_back(i);
			}
		}
		int y = 0, x = 0;
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				if (i == j) continue;
				y = start[i];
				x = start[j];
				sum1 += person[y][x];
				y = link[i];
				x = link[j];
				sum2 += person[y][x];
			}
		}
		g_min = min(g_min, abs(sum1 - sum2));
		link.clear();
		start.clear();
		return;
	}

	for (int i = index; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			func(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			person[i].push_back(num);
		}
	}
	visited.resize(N);
	func(0, 0);
	cout << g_min << '\n';
}