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
		temp.push_back(i + 1);
		func(cnt + 1);
		temp.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	func(0);
}