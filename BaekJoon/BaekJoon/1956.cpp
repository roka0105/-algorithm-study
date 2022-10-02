#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 405
int INF = 1000000000;
int V = 0;
int E = 0;
int d[MAX][MAX];
vector<pair<int, int>> arr[MAX];
int dijkstra(int start)
{
	priority_queue<pair<int, int>> queue;
	queue.push(make_pair(0, start));
	bool firstflag = false;
	while (!queue.empty())
	{
		int index = queue.top().second;
		int cost = -queue.top().first;
		
		if (firstflag == true && index == start)
		{
			return cost;
		}
		queue.pop();
		firstflag = true;
		if (d[start-1][index] < cost)
			continue;
		
		for (int i = 0; i < arr[index].size(); i++)
		{
			int dex = arr[index][i].second;
			int data = cost+arr[index][i].first;
			if (dex==start||d[start - 1][dex] > data)
			{
				d[start - 1][dex] = data;
				queue.push(make_pair(-data, arr[index][i].second));
			}
		}
	}
	return INF;
}
int main()
{
	cin >> V >> E;

	int y = 0;
	int x = 0;
	int distance = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> y >> x >> distance;
		arr[y].push_back(make_pair(distance, x));
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			d[i][j] = INF;
		}
	}
	int g_min = INF;
	for (int i = 0; i < V; i++)
	{
		g_min = min(g_min,dijkstra(i+1));
	}

	if (g_min == INF)
		cout << -1 << '\n';
	else
		cout << g_min << '\n';
}