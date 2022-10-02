#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define MAX 100
#define SEARCH 4
int N = 0;
int M = 0;

int g_map[MAX][MAX] = { {0} };
bool visited[MAX][MAX] = { {true,false} };
int g_min = MAX * MAX;
queue<pair<int, int>> index_queue;
//void dfs(int col, int row, int cnt)
//{
//	if (map[col][row] == 0)
//	{
//		return;
//	}
//	else if (col == N - 1 && row == M - 1)
//	{
//		g_min = min(g_min, cnt);
//		return;
//	}
//	//¾Æ·¡
//	if (col + 1 < N && map[col + 1][row] == 1 && visited[col + 1][row] == false)
//	{
//		visited[col + 1][row] = true;
//		dfs(col + 1, row, cnt + 1);
//		visited[col + 1][row] = false;
//	}
//	//À§
//	if (col - 1 >= 0 && map[col - 1][row] == 1 && visited[col - 1][row] == false)
//	{
//		visited[col - 1][row] = true;
//		dfs(col - 1, row, cnt + 1);
//		visited[col - 1][row] = false;
//	}
//	if (row + 1 < M && map[col][row + 1] == 1 && visited[col][row + 1] == false)
//	{
//		visited[col][row + 1] = true;
//		dfs(col, row + 1, cnt + 1);
//		visited[col][row + 1] = false;
//	}
//	if (row - 1 >= 0 && map[col][row - 1] == 1 && visited[col][row - 1] == false)
//	{
//		visited[col][row - 1] = true;
//		dfs(col, row - 1, cnt + 1);
//		visited[col][row - 1] = false;
//	}
//}
void bfs(int col, int row)
{
	int cnt = 1;
	visited[col][row] = true;
	
	index_queue.push(make_pair(col, row));
	pair<int, int> index;
	bool flag = false;
	while (index_queue.size() != 0)
	{
		flag = false;
		index = index_queue.front();
		index_queue.pop();
		
		if (index.first + 1 < N && visited[index.first + 1][index.second] == false && g_map[index.first+1][index.second] ==1)
		{
			visited[index.first + 1][index.second] = true;
			index_queue.push(make_pair(index.first + 1, index.second));
			g_map[index.first + 1][index.second] =g_map[index.first][index.second]+1;
			flag = true;
		}
		if (index.first - 1 >= 0 && visited[index.first - 1][index.second] == false && g_map[index.first-1][index.second] == 1)
		{
			visited[index.first - 1][index.second] = true;
			index_queue.push(make_pair(index.first - 1, index.second));
			g_map[index.first - 1][index.second] = g_map[index.first][index.second] + 1;
			flag = true;
		}
		if (index.second + 1 < M && visited[index.first][index.second + 1] == false && g_map[index.first][index.second+1] == 1)
		{
			visited[index.first][index.second + 1] = true;
			index_queue.push(make_pair(index.first, index.second + 1));
			g_map[index.first][index.second + 1] = g_map[index.first][index.second] + 1;
			flag = true;
		}
		if (index.second - 1 >= 0 && visited[index.first][index.second - 1] == false && g_map[index.first][index.second-1] == 1)
		{
			visited[index.first][index.second - 1] = true;
			index_queue.push(make_pair(index.first, index.second - 1));
			g_map[index.first][index.second - 1] = g_map[index.first][index.second] + 1;
			flag = true;
		}

	}
}
int main()
{
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			g_map[i][j] = str[j] - '0';
		}
	}
	bfs(0, 0);
	
	cout << g_map[N-1][M-1] << '\n';
}