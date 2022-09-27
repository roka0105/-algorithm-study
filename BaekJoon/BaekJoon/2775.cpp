#include <iostream>
using namespace std;
#define MAX1 100000
#define MAX2 14
int T = 0;
int K = 0;
int N = 0;

void func(int cnt, int* arr)
{
	int arr2[MAX2] = { 0, };
	if (cnt == K)
	{
		cout << arr[N - 1] << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			arr2[i] += arr[j];
		}
	}

	func(cnt + 1, arr2);
}
int main()
{
	cin >> T;
	int sum = 0;
	int arr[MAX2];
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			arr[j] = j + 1;
		}
		func(0, arr);
	}
}