#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 401
int INF = 1000000000;

vector<pair<int, int>> vec[MAX];
int d[MAX];
int V = 0;
int E = 0;
void d_clear()
{
	for (int i = 0; i < V; i++)
	{
		d[i] = INF;
	}
}
int func(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	bool flag = false;
	while (!pq.empty())
	{
		int index = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (flag == true && index == start)
		{
			return distance;
		}
		flag = true;
		if (d[index] < distance)continue;
		for (int i = 0; i < vec[index].size(); i++)
		{
			int idx = vec[index][i].second;
			int cost = distance + vec[index][i].first;

			if (idx == start || d[idx-1] > cost)
			{
				d[idx-1] = cost;
				pq.push(make_pair(-cost, idx));
			}
		}
	}
	return INF;
}
int main()
{
	cin >> V >> E;

	int x = 0;
	int y = 0;
	int n = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> y >> x >> n;
		vec[y].push_back(make_pair(n, x));
	}
	int g_min = INF;
	for (int i = 0; i < V; i++)
	{
		d_clear();
		g_min = min(g_min, func(i + 1));
	}
	if (g_min == INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << g_min << '\n';
	}
}