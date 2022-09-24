#include <iostream>
using namespace std;
#define MAX 26
struct Node
{
	char data;
	char left;
	char right;
};
Node node[MAX];
//char node[MAX];

void preorder(char _index)
{
	if (_index == '.')
	{
		return;
	}
	int index = _index - 'A';

	printf("%c", node[index]);
	preorder(node[index].left);
	preorder(node[index].right);
}
void inorder(char _index)
{
	if (_index == '.')
	{
		return;
	}
	int index = _index - 'A';
	
	
	inorder(node[index].left);
	printf("%c", node[index]);
	inorder(node[index].right);
}
void postorder(char _index)
{
	if (_index == '.')
	{
		return;
	}
	int index = _index - 'A';
	
	postorder(node[index].left);
	postorder(node[index].right);
	printf("%c", node[index]);
}
int main()
{
	int max_index = 0;
	cin >> max_index;
	getchar();
	char a, b, c;
	for (int i = 0; i < max_index; i++)
	{
		scanf("%c %c %c",&a,&b,&c);
		node[a - 'A'].data = a;
		node[a - 'A'].left = b;
		node[a - 'A'].right = c;
		getchar();
	}
	preorder(node[0].data);
	printf("\n");
	inorder(node[0].data);
	printf("\n");
	postorder(node[0].data);
}