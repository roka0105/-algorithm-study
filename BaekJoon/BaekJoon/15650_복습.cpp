#include <iostream>
#include <vector>
using namespace std;
#define MAX 9
int N, M;
vector<int> temp;
vector<bool> visited;
void func(int cnt)
{
	if (cnt == M)
	{
		bool flag = false;
		for (int i=0;i<temp.size()-1;i++)
		{
			if (temp[i] > temp[i + 1])
				flag = true;
		}
		if (!flag)
		{
			for (auto item : temp)
			{
				cout << item << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			temp.push_back(i + 1);
			func(cnt + 1);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	visited.resize(MAX);
	func(0);
}