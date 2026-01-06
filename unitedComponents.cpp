#include <iostream>
#include <vector>
using namespace std;
void dfs(int v, vector<vector<int>>& adj, vector<bool>visited) {
	visited[v] = true;
	for (int u : adj[v])
		if (!visited[u])
			dfs(u, adj, visited);
}
int componentNum(vector<vector<int>>& adj) {
	int n = adj.size();
	vector<bool>visited(n, false);
	int components = 0;

	for (int v = 0; v < n; v++) {
		if (!visited[v]) {
			dfs(v, adj, visited);
			components++;
		}
	}
	return components;
}

