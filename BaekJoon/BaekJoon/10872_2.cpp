#include <iostream>
using namespace std;

int func(int num)
{
	if (num > 2)
		num *= func(num - 1);

	return num;
}
int main()
{
	int num, result = 1;
	cin >> num;
	if (num != 0)
	{
		cout<<func(num)<<'\n';
	}
}