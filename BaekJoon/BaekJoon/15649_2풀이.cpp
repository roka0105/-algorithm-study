#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX] = { 0, };
bool visit[MAX] = { false, };
void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	dfs(0);
}