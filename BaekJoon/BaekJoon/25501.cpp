#include <iostream>
#include <string.h>
using namespace std;
int N = 0;
string str;
int g_count = 0;
int recursion(const char* s, int l, int r)//巩磊凯 矫累 林家客 场 林家
{
	g_count++;
	if (l >= r)
	{
		return 1;
	}
	else if (s[l] != s[r])return 0;
	else return recursion(s, l + 1, r - 1);
}
int isPalindrome(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		g_count = 0;
		cin >> str;
		cout << isPalindrome(str.c_str()) << ' ' << g_count << '\n';
	}
}