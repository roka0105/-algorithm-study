#include <iostream>
#define MAX 101
#define KMAX 10001
using namespace std;

int N = 0;
int K = 0;
int cost[MAX] = { 0, };
int num[KMAX] = { 1, };
void func(int _cost)
{
	for (int i = _cost; i <= K; i++)
	{
		num[i] = num[i] + num[i - _cost];
	}
	return;
}
int main()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
		func(cost[i]);
	}
	cout << num[K] << '\n';
	return 0;
}