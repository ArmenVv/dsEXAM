#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
DSU(int n) {
    parent.resize(n);
    rank.resize(n,0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return false;
    if (rank[x]<rank[y])
        swap(x,y);
    parent[y] = x;
    if (rank[x] == rank[y])
        rank[x]++;
    return true;
    }
private:
    vector<int> parent, rank;
};

struct Edge {
    int u, v, w;
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),[](Edge&a, Edge&b) {
        return a.w < b.w;
    });
    DSU dsu(n);
    int mstWeight = 0;
    int edgesUsed = 0;
    for (auto&e : edges) {
        if (dsu.unite(e.u,e.v)) {
            mstWeight += e.w;
            edgesUsed++;
            if (edgesUsed == n-1)
                break;
        }
    }
    return mstWeight;
}
