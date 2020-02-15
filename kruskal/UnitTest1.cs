#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// standard mst Kruskal code

vector<pair<int, pair<int, int>>> edges; // edges of the initial graph
vector<pair<int, pair<int, int>>> result; // edges that form mst
int p[100010]; // p[i] = parent of the vertex i
int sz[100010]; // size[i] = number of vertices in connectivity component with leader i
int totalcost = 0; // sum of weights of edges that form mst

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i; // vertex i is the parent of itself
        sz[i] = 1; // initial size of connectivity component with leader i is 1 
    }
}

int get_parent(int v)
{
    if (v == p[v]) return v; // if vertex is the parent of itself means that it is the leader
    else return p[v] = get_parent(p[v]); // otherwise we move to its parent
}

void merge(pair<int, pair<int, int>> edge)
{
    int cost = edge.first; // cost of the edge
    int u = edge.second.first; // first end of the edge
    int v = edge.second.second; // second end of the edge
    u = get_parent(u); // find the leader of connectivity component vertex u belongs to
    v = get_parent(v); // find the leader of connectivity component vertex v belongs to
    if (u == v)
    {
        return; // if vertices belong to the same connectivity component, then addition of the edge which is
                // under consideration will lead to cycle appearance (as we know tree is always acyclic)
    }
    else
    {
        result.push_back(edge); // otherwise we add this vertex to mst
        totalcost += cost; // and increase totalcost
        if (sz[u] >= sz[v])
        { // if component with leader u is bigger that
            p[v] = u; // it is better to make u leader of union of two components
            sz[u] += sz[v]; // and update total size
        }
        else
        { // otherwise
            p[u] = v; // it is better to make v leader of union of two components
            sz[v] += sz[u]; // and update total size
        }
    }
}

int main()
{
    int n; cin >> n;
    init(n);
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back(make_pair(cost, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++)
    {
        merge(edges[i]);
    }
    // now totalcost is the cost of mst
    // and result contains all the edges that form mst
    return 0;
}