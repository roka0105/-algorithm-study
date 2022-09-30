#include <iostream>
using namespace std;

long long S = 0;

int main()
{
	cin >> S;
	long long sum = 0;
	int cnt=0;
	int i = 1;
	while(1)
	{
		sum += i;
		cnt++;
		if (sum > S)
		{
			cnt--;
			break;
		}
		i++;
	}
	cout << cnt << '\n';
}
