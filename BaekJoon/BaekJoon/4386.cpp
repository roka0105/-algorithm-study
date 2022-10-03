#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int GetParent(vector<int>& c, int num)
{
	if (c[num] == num) return num;
	return c[num] = GetParent(c, c[num]);
}
bool FindParent(vector<int> c, int a, int b)
{
	a = GetParent(c, a);
	b = GetParent(c, b);
	if (a == b) return true;
	else return false;
}
void Union(vector<int>& c, int a, int b)
{
	a = GetParent(c, a);
	b = GetParent(c, b);
	if (a < b)
		c[b] = a;
	else c[a] = b;
}
class Edge
{
public:
	int node[2];
	double distance;
	Edge(int s, int e, double c)
	{
		node[0] = s;
		node[1] = e;
		distance = c;
	}
	bool operator<(const Edge& e)
	{
		return this->distance < e.distance;
	}
};
vector<pair<double, double>> vertex;
vector<Edge> edge;
vector<int>cycle;
int N = 0;
int main()
{
	cin >> N;

	double x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		vertex.push_back(make_pair(x, y));
	}
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cycle.push_back(i);
		for (int j = 0; j < N; j++)
		{
			if (i == j)continue;
			a = vertex[j].first - vertex[i].first;
			b = vertex[j].second - vertex[i].second;
			edge.push_back(Edge(i, j, sqrt((a * a) + (b * b))));
		}
	}
	sort(edge.begin(), edge.end());
	double sum = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		if (!FindParent(cycle, edge[i].node[0], edge[i].node[1]))
		{
			sum += edge[i].distance;
			Union(cycle, edge[i].node[0], edge[i].node[1]);
		}
	}
	printf("%.2lf\n", sum);
}