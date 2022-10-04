#include <iostream>
using namespace std;
#define MAX 16
int arr[MAX];
int g_count = 0;
int N = 0;
bool check(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] == arr[cnt] || abs(arr[cnt] - arr[i]) == abs(cnt - i))
		{
			return false;
		}
	}
	return true;
}
void func(int cnt)
{
	if (cnt == N)
	{
		g_count++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr[cnt] = i;
		if (check(cnt))
		{
			func(cnt + 1);
			arr[cnt] = -1;
		}
	}
}

int main()
{
	cin >> N;
	func(0);
	cout << g_count << '\n';
}