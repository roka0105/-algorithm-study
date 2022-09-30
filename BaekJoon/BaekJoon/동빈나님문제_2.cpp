#include <iostream>
#include <string>
using namespace std;
#define MAX 200000000
string str;
int number[MAX];
int main()
{
	cin >> str;
	int result = 0;
	int strsize = str.size();

	for (int i = 0; i < strsize; i++)
	{
		number[i] = stoi(str.substr(i, 1));
	}
	int num = number[0];
	for (int i = 1; i < strsize; i++)
	{
		if (num<=1||result<=1)
		{
			result += number[i];
		}
		else
		{
			result *= number[i];
		}
		num = number[i];
	}
	cout << result << '\n';
}