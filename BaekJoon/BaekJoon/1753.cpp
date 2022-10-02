#include <iostream>
#include <queue>
#include <vector>
#define MAX 20000
using namespace std;

vector<pair<int, int>> vec[MAX];
int INF = 1000000000;
int V = 0;
int E = 0;
int K = 0;
int d[MAX];
void d_clear()
{
	for (int i = 0; i < V; i++)
	{
		/*if (i + 1 == K)
		{
			d[i] = 0;
		}
		else*/
			d[i] = INF;
	}
}
void func(int start)
{
	d[start-1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int index = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (d[index-1] < distance)continue;

		for (int i = 0; i < vec[index].size(); i++)
		{
			int idx = vec[index][i].second;
			int data = distance + vec[index][i].first;

			if (d[idx - 1] > data)
			{
				d[idx - 1] = data;
				pq.push(make_pair(-data, idx));
			}
		}
	}

}
int main()
{
	cin >> V >> E >> K;

	int x = 0;
	int y = 0;
	int num = 0;

	for (int i = 0; i < E; i++)
	{
		cin >> y >> x >> num;
		vec[y].push_back(make_pair(num, x));
	}

	d_clear();
	func(K);

	for (int i = 0; i < V; i++)
	{
		if (d[i] == INF)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << d[i] << '\n';
		}
	}
}