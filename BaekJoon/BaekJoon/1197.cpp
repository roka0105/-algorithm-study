#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
#define NMAX 1000000
#define EMAX 100000

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}
int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)return 1;
	else return 0;
}

class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int d)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = d;
	}
	bool operator<(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

vector<Edge> node;
int V = 0;
int E = 0;
int cycle[MAX];
int parent(int n)
{
	if (cycle[n] == n) return n;
	return cycle[n] = parent(cycle[n]);
}
int main()
{
	cin >> V >> E;

	int start = 0, end = 0, cost = 0;
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> cost;
		node.push_back(Edge(start, end, cost));
	}
	sort(node.begin(), node.end());
	for (int i = 0; i < V; i++)
	{
		cycle[i]=i;
	}
	int sum = 0;
	for (int i = 0; i < node.size(); i++) {
		// 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택 
		if (!find(cycle, node[i].node[0] - 1, node[i].node[1] - 1)) {
			sum += node[i].distance;
			unionParent(cycle, node[i].node[0] - 1, node[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
}
