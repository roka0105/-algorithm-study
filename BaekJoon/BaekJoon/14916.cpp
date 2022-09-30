#include <iostream>
using namespace std;
#define MAX 100001
int cost[2][2] = { {2,0},{5,0} };
int N = 0;
int main()
{
	cin >> N;
	int cur = 0;
	int result = N;
	cost[1][1] = result / cost[1][0]; // N / 5
	int index = cost[1][1]; 
	for (int i = 0; i < index+1; i++)
	{
		result = N - (cost[1][0] * cost[1][1]); // N-(5*x)
		if (result == 0) // 5로 나누어 떨어진 경우
		{
			cout << cost[1][1] << '\n';
			return 0;
		}
		if (result % cost[0][0] != 0)//2로 나누어서 안 나누어 떨어진 경우
		{
			if (cost[1][1] == 0) //거스름돈을 줄 수 없는 경우
			{
				cout << -1 << '\n';
				return 0;
			}
			//안나눠떨어진것
			cost[1][1]--;
		}
		else //2로 나누어서 나누어 떨어진 경우
		{
			cost[0][1] = result / cost[0][0];
			cout << cost[0][1] + cost[1][1] << '\n';
			return 0;
		}
	}
}