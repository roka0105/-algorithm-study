#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1000
int N = 0;
int M = 0;
int arr[MAX][MAX] = { {0} };
bool visited[MAX][MAX] = { {false} };
bool wall[MAX];
queue<pair<int, int>> index_queue;
int g_day = 0;
int zero_cnt = 0;
int live_cnt = 0;
int wall_cnt = 0;
int cur_index = 0;
bool movecheck(int col, int row)
{
	if (col < M && col >= 0 && row < N && row >= 0)
		return true;
	return false;
}
void bfs()
{
	while (index_queue.size() != 0)
	{
		pair<int, int> index = index_queue.front();
		index_queue.pop();

		
		if (movecheck(index.first+1,index.second)&& arr[index.first + 1][index.second] == 0)
		{
			index_queue.push(make_pair(index.first + 1, index.second));
			arr[index.first + 1][index.second] = arr[index.first][index.second] + 1;
		}
		if (movecheck(index.first - 1, index.second) && arr[index.first - 1][index.second] == 0)
		{
			index_queue.push(make_pair(index.first - 1, index.second));
			arr[index.first - 1][index.second] = arr[index.first][index.second] + 1;
		}
		if (movecheck(index.first, index.second+1) && arr[index.first][index.second + 1] == 0)
		{
			index_queue.push(make_pair(index.first, index.second + 1));
			arr[index.first][index.second + 1] = arr[index.first][index.second] + 1;
		}
		if (movecheck(index.first, index.second-1) && arr[index.first][index.second - 1]==0)
		{	
			index_queue.push(make_pair(index.first, index.second - 1));
			arr[index.first][index.second - 1] = arr[index.first][index.second] + 1;
		}
	}
}
int main()
{
	cin >> N >> M;
	pair<int, int> start_index;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j]==1)
			index_queue.push(make_pair(i, j));
		}
	}

	bfs();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
			g_day = max(g_day, arr[i][j]);
		}
	}
	
	cout << g_day-1 << '\n';
	return 0;
}