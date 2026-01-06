#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>>& adj) {
	int n = adj.size();
	vector<bool>visited(n, false);
	queue<int>q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int u : adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
			}
		}
	}
}

void bfsRecursive(vector<vector<int>>& adj, vector<bool>& visited, vector<int> current_level) {
	if (current_level.empty()) return;
	vector<int> next_level;
	for (int v : current_level) {
		cout << v << " ";
		visited[v] = true;
	}
	for (int v : current_level) {
		for (int u : adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				next_level.push_back(u);
			}
		}
	}
	bfsRecursive(adj, visited, next_level);
}
