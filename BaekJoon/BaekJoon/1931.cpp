#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001
vector<pair<int, int>> meeting;
vector<bool>visited;
int N = 0;
int g_max = 1;

//void func(int cnt, int start_time, int _count)
//{
//	g_max = max(g_max, _count);
//	int befor_time = start_time;
//	for (int i = cnt; i < meeting.size(); i++)
//	{
//		if (start_time <= meeting[i].first && visited[i] == false)
//		{
//			visited[i] = true;
//			start_time = meeting[i].second;
//			func(cnt + 1, start_time, _count + 1);
//			start_time = befor_time;
//			visited[i] = false;
//		}
//	}
//}
//bool mysort(const pair<int, int>& data, const pair<int, int>& data2)
//{
//	return data.first < data2.first;
//}
int main()
{
	cin >> N;

	int start = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		meeting.push_back(make_pair(end, start));
	}
	sort(meeting.begin(), meeting.end());
	//visited.resize(N);
	//func(0, 0, 0);
	int time = meeting[0].first;
	for (int i = 1; i < N; i++)
	{
		if (time <= meeting[i].second)
		{
			time = meeting[i].first;
			g_max++;
		}
	}
	cout << g_max << '\n';
}