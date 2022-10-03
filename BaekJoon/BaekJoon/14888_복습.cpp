#include <iostream>
#include <vector>
using namespace std;

vector<int> number;
vector<int> op;
int N = 0;
int g_max = -1000000000;
int g_min = 1000000000;
void func(int cnt, int sum)
{
	if (cnt == N)
	{
		g_max = max(g_max, sum);
		g_min = min(g_min, sum);
		return;
	}
	int befornum = sum;

	for (int j = 0; j < op.size(); j++)
	{
		if (op[j] != 0)
		{
			op[j] -= 1;
			switch (j)
			{
			case 0:
				sum += number[cnt];
				break;
			case 1:
				sum -= number[cnt];
				break;
			case 2:
				sum *= number[cnt];
				break;
			case 3:
				sum /= number[cnt];
				break;
			}
			func(cnt + 1, sum);
			op[j] += 1;
			sum = befornum;
		}
	}

}
int main()
{
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		number.push_back(num);
	}
	int _op = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> _op;
		op.push_back(_op);
	}
	func(1, number[0]);
	cout << g_max << '\n' << g_min;
}