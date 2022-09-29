#include <iostream>
using namespace std;
#define MAX 100
unsigned long long result[MAX] = { 0,1, };
int N = 0;
void F(int num)
{

	for (int i = 2; i <= num; i++)
	{
		result[i]=result[i - 2] + result[i-1];
	}
	cout << result[num] << '\n';
}
int main()
{
	cin >> N;
	F(N);
	return 0;
}