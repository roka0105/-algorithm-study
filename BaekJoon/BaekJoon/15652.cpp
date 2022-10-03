#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> temp;
void func(int cnt)
{
	if (cnt == M)
	{
		for (auto item : temp)
		{
			cout << item << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (temp.size() != 0)
		{
			if (temp.back() <= i+1)
			{
				temp.push_back(i + 1);
				func(cnt + 1);
				temp.pop_back();
			}
		}
		else if (cnt == 0)
		{
			temp.push_back(i + 1);
			func(cnt + 1);
			temp.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	func(0);
}