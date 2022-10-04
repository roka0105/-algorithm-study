#include <iostream>
#include <vector>
#define MAX 21
using namespace std;
vector<int> arr;
int N = 0;
void func(int cnt,int num1,int num2)
{
	if (cnt == N+1)
	{
		cout << num1 << '\n';
		return;
	}
	int num3 = num1 + num2;
	if(cnt!=2)
	num2 = num1;
	func(cnt + 1,num3,num2);
}
int main()
{
	cin >> N;
	if (N == 0)
		cout << 0 << '\n';
	else if (N == 1)
		cout << 1 << '\n';
	else
	func(2,0,1);
}