#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001
int N = 0;
int M = 0;
bool visited[MAX] = { false, };
vector<int> node[MAX];
int result[MAX] = { 0, };
int cnt = 1;
void dfs(int select)
{
	result[select - 1] = cnt;
	if (select == 0)
		return;
	visited[select - 1] = true;
	cnt++;
	for (auto item : node[select - 1])
	{
		if (visited[item - 1] != true)
			dfs(item);
	}
}
int main()
{
	int start = 0;
	cin >> N >> M >> start;
	int vertex_index = 0;
	int num = 0;
	int check = 0;
	
	for (int i = 0; i < M; i++)
	{
		cin >> vertex_index;
		cin >> num;
		if (vertex_index!= 0 && num != 0)
		{
			node[vertex_index - 1].push_back(num);
			node[num - 1].push_back(vertex_index);
			check++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		sort(node[i].begin(), node[i].end(), greater<int>());
	}
	dfs(start);
	for (int i = 0; i < N; i++)
		cout << result[i] << '\n';
	return 0;
}