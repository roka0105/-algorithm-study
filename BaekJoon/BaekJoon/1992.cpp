#include <iostream>
using namespace std;
#define Quad 4
bool QuadTree[64][64];
void QuadPrint(int row, int col, int num)
{
	const char* check[Quad];
	if (num == 1)
	{
		cout << QuadTree[row][col];
		return;
	}

	int truecount = 0;
	for (int i = row; i < row+num; i++)
	{
		for (int j = col; j < col + num; j++)
		{
			if (QuadTree[i][j] == true)
			{
				++truecount;
			}
		}
	}

	if (truecount == num*num)
	{
		cout << "1";
		return;
	}
	else if (truecount == 0)
	{
		cout << "0";
		return;
	}

	cout << "(";
	//위 왼쪽 검사
	QuadPrint(row, col, num / 2);
	//위 오른쪽 검사
	QuadPrint(row, col + (num / 2), num / 2);
	//아래 왼쪽 검사
	QuadPrint(row + (num / 2), col, num / 2);
	//아래 오른쪽 검사
	QuadPrint(row + (num / 2), col + (num / 2), num / 2);
	cout << ")";
}
int main()
{
	int num = 0;
	do
	{
		cin >> num;
	} while (num <= 0 || num > 64);

	char c;
	for (int i = 0; i < num; i++)
	{
		getchar();
		for (int j = 0; j < num; j++)
		{
			scanf("%c", &c);
			if (c == '1')
				QuadTree[i][j] = true;
			else
				QuadTree[i][j] = false;
		}
	}
	getchar();

	QuadPrint(0, 0, num);
	cout << endl;
}