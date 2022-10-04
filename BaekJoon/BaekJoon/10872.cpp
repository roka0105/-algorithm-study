#include <iostream>
using namespace std;

int N = 0;
void func(int cnt,int sum)
{
	if (cnt == N + 1)
	{
		cout << sum << '\n';
		return;
	}
	sum *= cnt;
	func(cnt + 1,sum);
}
int main()
{
	cin >> N;

	func(1,1);
}