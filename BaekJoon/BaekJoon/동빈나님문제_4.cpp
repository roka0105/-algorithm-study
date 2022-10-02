#include <iostream>
#include <string>
using namespace std;
#define L -1
#define R +1
#define U -1
#define D +1
#define MAX 100
int N = 0;
string str;
int pos[MAX][MAX] = { {0,0} };
int main()
{
	cin >> N;
	cin >> str;
	int strsize = str.size();
	int xpos = 0;
	int ypos = 0;
	char c = ' ';
	for (int i = 0; i < strsize; i++)
	{
		c = str[i];
		
		switch (c)
		{
		case 'R':
			if (xpos < MAX)
			{
				xpos += R;
			}
			break;
		case 'L':
			if (xpos > 0)
			{
				xpos += L;
			}
			break;
		case 'U':
			if (ypos > 0)
			{
				ypos += U;
			}
			break;
		case 'D':
			if (ypos < MAX)
			{
				ypos += D;
			}
			break;
		}
	}
	cout << ypos+1 << ' ' << xpos+1 << '\n';
}