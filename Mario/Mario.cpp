#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> g[100];
int used[100];
int d[100];
queue<int> q;
int n, m, x, y;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[0][0] == 2 || g[0][m - 1] == 2 || g[n - 1][0] == 2 || g[n - 1][m - 1] == 2) {
				g[i][j]
			}
		}
	}
	return 0;
}