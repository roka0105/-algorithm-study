#include <iostream>
using namespace std;
#define INF 1e9


int graph[501][501];

int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n+1; i++)
	{
		fill(graph[i], graph[i] + n+1, INF);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] > c)
			graph[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] != INF && graph[k][j] != INF)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << graph[i][j] << ' ';
			}
		}
		cout << '\n';
	}

}