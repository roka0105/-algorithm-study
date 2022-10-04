#include <iostream>
using namespace std;

int N = 0;
int func(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;

	return func(num - 1) + func(num - 2);
}
int main()
{
	cin >> N;
	cout<<func(N)<<'\n';
}