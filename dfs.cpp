#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[v] = true;
	cout << v << " ";
	for (int u : adj[v]) {
		if (!visited[u])
			dfs(u, adj, visited);
	}
}	

void dfsIterative(int start, vector<vector<int>>& adj) {
	int n = adj.size();
	vector<bool> visited(n, false);
	stack<int> st;
	st.push(start);
	while (!st.empty()) {
		int v = st.top();
		st.pop();
		if (visited[v]) continue;
		visited[v] = true;
		cout << v << " ";
		for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
			if (!visited[*it])
				st.push(*it);
		}
	}
}
