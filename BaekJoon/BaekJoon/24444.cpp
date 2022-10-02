#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001
int N = 0;
int M = 0;
int R = 0;
queue<int> _next;
vector<int> node[MAX];
bool visited[MAX] = { false, };
int result[MAX] = { 0, };
int cnt = 1;
void bfs(int start)
{
	visited[start-1] = true;

	_next.push(start);
	int num = 0;

	while (_next.size()!= 0)
	{
		num = _next.front();
		_next.pop();
		result[num-1] = cnt++;
		for (auto item : node[num-1])
		{
			if (visited[item-1] != true && item != 0)
			{
				visited[item-1] = true;
				
				_next.push(item);
			}
		}
	}

}
int main()
{
	cin >> N >> M >> R;

	int vertex_index = 0;
	int edge_index = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> vertex_index;
		cin >> edge_index;
		node[vertex_index - 1].push_back(edge_index);
		node[edge_index - 1].push_back(vertex_index);
	}

	for (int i = 0; i < N; i++)
	{
		sort(node[i].begin(), node[i].end(), less<int>());
	}


	bfs(R);
	
	for (int i = 0; i < N; i++)
	{
		cout << result[i] << '\n';
	}

}