#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> g[1000];
int anss = 0;

vector<bool> us;
int ans = 0;

void dfs(int v, int depth) {
	us[v] = true;
	if (depth == 1)
	{
		for (int i = 0; i < g[v].size(); ++i)
		{
			if (!us[g[v][i]])
			{
				anss++;
			}
		}
	}
	for (int i = 0; i < g[v].size(); ++i)
	{
		if (!us[g[v][i]])
		{
			dfs(g[v][i], --depth);
		}
	}
}

void bfs(int a, int depth) {
	queue<int> qu;
	bool used[100];
	qu.push(a);
	used[a] = true;
	while (!qu.empty()) {
		a = qu.front();
		if (depth == 1)
		{
			break;
		}
		qu.pop();
		for (int i = 0; i < g[a].size(); ++i)
		{
			int y = g[a][i];
			if (!used[y])
			{
				used[y] = true;
				qu.push(y);
			}
		}
		depth--;
	}
	while (!qu.empty()) {
		int a = qu.front();
		qu.pop();
		for (int i = 0; i < g[a].size(); ++i)
		{
			if (!used[g[a][i]])
			{
				anss++;
				used[g[a][i]] = true;
			}
		}
	}
}

int main(int argc, char const* argv[])
{
	int n, m;
	cin >> n >> m;
	us.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int q, w;
		cin >> q >> w;
		g[q - 1].push_back(w - 1);
		g[w - 1].push_back(q - 1);
	}
	int q;
	cin >> q;
	vector<int> ans;
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin >> a >> b;
		bfs(a - 1, b);
		ans.push_back(anss);
		anss = 0;
		// vector<bool> usn(n);
		// us = usn;
	}
	for (int i = 0; i < q; ++i)
	{
		cout << ans[i] << endl;
	}
	cin >> n;
	return 0;
}