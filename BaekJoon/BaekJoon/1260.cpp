#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000

int N = 0;
int M = 0;
int V = 0;
vector<int> node[MAX];
vector<int> result;
bool visited[MAX] = { false };
queue<int> g_index;
void init(int count)
{
	for (int i = 0; i < count; i++)
	{
		visited[i] = false;
	}
	result.clear();
}
void print()
{
	for (auto item : result)
	{
		cout << item << ' ';
	}
	cout << '\n';
}
void bfs(int num)
{
	visited[num - 1] = true;
	g_index.push(num);
	int n = 0;
	while (g_index.size() != 0)
	{
		n = g_index.front();
		g_index.pop();
		result.push_back(n);
		for (auto item : node[n - 1])
		{
			if (visited[item - 1] == false)
			{
				visited[item - 1] = true;
				g_index.push(item);
			}
		}
	}
}
void dfs(int num)
{
	visited[num - 1] = true;
	result.push_back(num);

	for (auto item : node[num - 1])
	{
		if (visited[item - 1] == false)
		{
			dfs(item);
		}
	}
}
int main()
{
	cin >> N >> M >> V;

	int vertex_index = 0;
	int num = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> vertex_index >> num;
		node[vertex_index - 1].push_back(num);
		node[num - 1].push_back(vertex_index);
	}
	for (int i = 0; i < N; i++)
	{
		sort(node[i].begin(), node[i].end(),less<int>());
	}
	dfs(V);
	print();
	init(N);
	bfs(V);
	print();
}