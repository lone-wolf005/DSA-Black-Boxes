#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (size[rootX] < size[rootY]) {
            std::swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }
};

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (const auto& edge : edges) {
            if (!uf.unite(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }
        return {};
    }
};
