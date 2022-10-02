#include <iostream>
using namespace std;
#define INF 1000000000
int num = 6;
int arr[6][6] =
{
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0},
};
bool visited[6];
int d[6];
int getSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < num; i++)
	{
		if (d[i] < min && !visited[i])
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int start)
{
	for (int i = 0; i < num; i++)
	{
		d[i] = arr[start][i];
	}
	visited[start] = true;
	for (int i = 0; i < num-2; i++)
	{
		int current = getSmallIndex();
		visited[current] = true;
		for (int j = 0; j < 6; j++)
		{
			if (!visited[j])
			{
				if (d[current] + arr[current][j] < d[j])
				{
					d[j] = d[current] + arr[current][j];
				}
			}
		}
	}
}
int main()
{
	dijkstra(0);
	for (int i = 0; i < num; i++)
	{
		cout << d[i] << ' ';
	}
}