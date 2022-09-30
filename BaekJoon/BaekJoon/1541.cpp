#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 51

string num;

string str;
char cul = ' ';
int main()
{
	cin >> str;
	int strsize = str.size();

	//int numindex = 0;
	//int beforindex = 0;
	int index = 0;
	int sum = 0;
	while (index <= strsize)
	{
		switch (str[index])
		{
		case '+':
		case '-':
		case '\0':
			/*if (num[0]=='0' && stoi(num) != 0)
			{
				cout << 0 << '\n';
				return 0;
			}
			else
			{
				for (int i = 0; i < numindex; i++)
				{
					num[i] = '\0';
				}
				numindex = 0;
			}*/
			
			if (cul == '-')
			{
				sum -= (stoi(num));
				num = "";
			}
			else
			{
				sum += (stoi(num));
				cul = str[index];
				num = "";
			}
			//beforindex = index + 1;
			index++;
			break;
		default:
			num += str[index];
			index++;
		}
	}
	cout << sum << '\n';
}