#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> temp;
void func(int index, int cnt)
{
	if (cnt == 0)
	{
		for (auto item : temp)
		{
			cout << item << ' ';
		}
		cout << '\n';
		return;
	}
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		flag = false;
		for (auto item : temp)
		{
			if (i+1 == item)
				flag = true;
		}
		if (flag) continue;
		temp.push_back(i+1);
		func(i + 1, cnt - 1);
		temp.pop_back();
	}
}
int main()
{
	cin >> N >> M;

	func(0, M);

}