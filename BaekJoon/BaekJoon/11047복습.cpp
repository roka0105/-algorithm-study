#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cost;
int N = 0, K = 0;
void func()
{
	int sum = K;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		count+=(sum / cost[i]);
		sum = sum % cost[i];
	}
	cout << count << '\n';
}
int main()
{
	cin >> N >> K;
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		cost.push_back(c);
	}
	sort(cost.begin(), cost.end(), greater<int>());
	func();
}