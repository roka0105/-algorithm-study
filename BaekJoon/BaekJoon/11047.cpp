#include <iostream>
using namespace std;
#define MAX 1000000
int N = 0;
int K = 0;
int cost[MAX] = { 1 };
int g_count = 0;
void func()
{
	for (int i = N; i >= 0; i--)
	{
		if (K < cost[i])
			continue;
		K -= cost[i];
		i += 1;
		g_count++;
	}
	cout << g_count << '\n';
}
int main()
{
	cin >> N;
	cin >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}
	func();

}