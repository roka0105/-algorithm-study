#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
#define MAX2 10000
int N = 0;
int arr[MAX] = { 0 };
bool check[MAX] = { false };
int g_max = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+N,less<int>());
	for (int i = 0; i < N; i++)
	{
		g_max = max(g_max, (N - i) * arr[i]);
	}
	cout << g_max << '\n';
}