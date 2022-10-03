#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
#define NMAX 1000000
#define EMAX 100000

struct Node
{
	int s_index;
	int e_index;
	int cost;
	Node(int s, int e, int c)
	{
		s_index = s;
		e_index = e;
		cost = c;
	}
	void set(int s, int e, int c)
	{
		s_index = s;
		e_index = e;
		cost = c;
	}
};
bool compare(const Node& _node1, const Node& _node2)
{
	return _node1.cost < _node2.cost;
}
vector<Node> node;
int V = 0;
int E = 0;
vector<int> cycle;
int parent(int n)
{
	if (cycle[n] == n) return n;
	return cycle[n]=parent(cycle[n]);
}
void func()
{
	int cost = 0;
	int start = node[0].s_index;
	int num = 0;
	for (int i = 0; i < E; i++)
	{
		Node n = node[i];
		if (num == V - 1)
		{
			cout << cost << '\n';
			return;
		}
		if (parent(n.e_index - 1) == parent(n.s_index - 1))
			continue;
		else
		{
			if (parent(n.e_index - 1) < parent(n.s_index - 1))
			{
				cycle[n.s_index - 1] = parent(n.e_index - 1);
			}
			else 
			{
				cycle[n.e_index - 1] = parent(n.s_index - 1);
			}
			cost += n.cost;
		}
		num++;
	}
	cout << cost << '\n';
}
int main()
{
	cin >> V >> E;

	int start = 0, end = 0, cost = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> cost;
		node.push_back(Node(start, end, cost));
	}
	sort(node.begin(), node.end(), compare);
	for (int i = 0; i < V; i++)
	{
		cycle.push_back(i + 1);
	}
	func();
}
