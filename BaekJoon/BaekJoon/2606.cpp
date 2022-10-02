#include <iostream>
#include <vector>
using namespace std;
#define MAX 100
vector<int> node[MAX];
bool visited[MAX] = { false, };
int cnt = 0;
int N = 0;
int M = 0;
void dfs(int num)
{
	visited[num-1] = true;
	for (int i = 0; i < node[num - 1].size(); i++)
	{
		int n = node[num - 1][i];
		if (visited[n-1] == false)
		{
			cnt++;
			dfs(n);
		}
	}
}
int main()
{
	cin >> N >> M;
	int vertex_index = 0;
	int num = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> vertex_index;
		cin >> num;
		node[vertex_index - 1].push_back(num);
		node[num - 1].push_back(vertex_index);
	}
	dfs(1);
	cout << cnt << '\n';
}