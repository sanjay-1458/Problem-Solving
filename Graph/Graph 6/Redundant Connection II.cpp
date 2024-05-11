class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n){
        rank.resize(n,1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    int merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu != pv) {
            if (rank[pu] >= rank[pv]) {
                parent[pv] = pu;
                rank[pu] += rank[pv];
            } else {
                parent[pu] = pv;
                rank[pv] += rank[pu];
            }
            return 1;
        } else {
            return -1;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indeg(n,0);

        int node = -1;
        int k = -1;
        for (int i = 0; i < n; ++i) {
            int val = edges[i][1] - 1;
            if (++indeg[val] == 2) {
                node = val;
                k = i;
                break;
            }
        }

        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            if (i == k) continue;
            int n1 = edges[i][0] - 1;
            int n2 = edges[i][1] - 1;

            int x = dsu.merge(n1, n2);
            if (x == -1) {
                if (k == -1) return edges[i];
                for (int j = 0; j <= i; ++j) {
                    if (j == k) continue;
                    if (edges[j][1] - 1 == node) return edges[j];
                }
            }
        }
        return edges[k];
    }
};
