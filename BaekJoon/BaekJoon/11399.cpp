#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N = 0;
vector<int> wait_time;
int main()
{
	cin >> N;

	int t = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		wait_time.push_back(t);
	}
	sort(wait_time.begin(), wait_time.end(), less<int>());
	int sum = wait_time[0];
	for (int i = 1; i < N; i++)
	{
		wait_time[i] = wait_time[i]+wait_time[i-1];
		sum += wait_time[i];
	}
	cout << sum << '\n';
}