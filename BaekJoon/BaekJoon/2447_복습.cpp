#include <iostream>
using namespace std;

int N = 0;
int K = 0;
void func(int cnt, int start, int to, int pass)
{
	if (cnt == 1)
	{
		cout << start << ' ' << to << '\n';
	}
	else
	{
		func(cnt - 1, start, pass, to);
		cout << start << ' ' << to<<'\n';
		func(cnt - 1, to, pass, start);
	}
}
int main()
{
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	func(N, 1, 3, 2);
}