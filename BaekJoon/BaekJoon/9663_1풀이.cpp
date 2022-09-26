//�ð� �ʰ� �ڵ�
#include <iostream>
using namespace std;
#define MAX 15
int N = 0;
int result = 0;
bool enable[MAX][MAX] = { false, };

void down_Enable(int i, int j, bool flag)
{
	if (i < 0 || j < 0 || i >= 8 || j >= 8)
	{
		return;
	}
	enable[i][j] = flag;
	down_Enable(i + 1, j, flag);
}
void left_Enable(int i, int j, bool flag)
{
	if (i < 0 || j < 0 || i >= 8 || j >= 8)
	{
		return;
	}
	enable[i][j] = flag;
	left_Enable(i, j - 1, flag);
}
void leftdown_Enable(int i, int j, bool flag)
{
	if (i < 0 || j < 0 || i >= 8 || j >= 8)
	{
		return;
	}
	enable[i][j] = flag;
	leftdown_Enable(i + 1, j - 1, flag);
}
void rightdown_Enable(int i, int j, bool flag)
{
	if (i < 0 || j < 0 || i >= 8 || j >= 8)
	{
		return;
	}
	enable[i][j] = flag;
	rightdown_Enable(i + 1, j + 1, flag);
}

void Enable(int i, int j, bool flag)
{
	down_Enable(i + 1, j, flag);
	leftdown_Enable(i + 1, j - 1, flag);
	rightdown_Enable(i + 1, j + 1, flag);
}
void Queen(int row, int col, int cnt)
{
	bool beforable[MAX][MAX] = { false, };
	if (cnt == N)
	{
		++result;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				beforable[x][y] = enable[x][y];
			}
		}
		//���� ���õ� ����� �������� ���� true �����
		Enable(row, col, true);
		if (enable[row + 1][i] == false)
		{
			//���� ����.
			Queen(row + 1, i, cnt + 1);
		}
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				enable[x][y] = beforable[x][y];
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Queen(0, i, 1);
	}
	cout << result << '\n';
}