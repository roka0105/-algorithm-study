#include <iostream>
using namespace std;
#define MAX 15
int N = 0;
int result = 0;

int col[MAX];
bool check(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (col[cnt] == col[i] || abs(col[cnt] - col[i]) == cnt - i)
		{
			return false;
		}
	}
	return true;
}
void Queen(int cnt)
{
	if (cnt == N)
	{
		++result;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		col[cnt] = i;
		if (check(cnt) == true)
		{
			Queen(cnt + 1);
		}
	}
}
int main()
{
	cin >> N;

	Queen(0);


	cout << result << '\n';
}