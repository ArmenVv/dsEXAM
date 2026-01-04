#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
	int x, y;
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int waveAlgorithm(vector<vector<int>>& grid, Cell start, Cell end) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<Cell>q;
	
	q.push(start);
	dist[start.x][start.y] = 0;

	while (!q.empty()) {
		Cell cur = q.front();
		q.pop();
		if (cur.x == end.x && cur.y == end.y)
			return dist[cur.x][cur.y];
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return -1;
}

int main() {
	vector<vector<int>> grid = {
		{0, 0, 0, 1},
		{0, 1, 0, 0},
		{0, 0, 0, 0}
	};

	Cell start = { 0, 0 };
	Cell end = { 2, 3 };

	int shortestPath = waveAlgorithm(grid, start, end);
	cout << "Минимальное расстояние: " << shortestPath << endl;
}
