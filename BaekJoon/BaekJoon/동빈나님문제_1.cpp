#include <iostream>
using namespace std;

int N = 0;
int K = 0;
int main()
{
	cin >> N;
	cin >> K;
	int cnt = 0;
	int curnum = N;

	while (1)
	{
		if (curnum % K == 0)
		{
			curnum /= K;
		}
		else
		{
			curnum -= 1;
		}
		if (curnum == 0)
			break;
		cnt++;
	}
	cout << cnt << '\n';
}