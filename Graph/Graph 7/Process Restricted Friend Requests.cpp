
class DSU {
    vector<int> rank;
    vector<int> parent;

public:
    DSU(int n) {
        initialize(n);
    }

    void initialize(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& rst, vector<vector<int>>& reqs) {
        DSU dsu(n);
        vector<bool> ans;
        for (int i = 0; i < reqs.size(); i++) {
            bool res = processRequest(dsu, rst, reqs[i]);
            if (res) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }

private:
    bool processRequest(DSU& dsu, const vector<vector<int>>& rst, const vector<int>& req) {
        int px = dsu.find(req[0]);
        int py = dsu.find(req[1]);
        for (int j = 0; j < rst.size(); j++) {
            int px1 = dsu.find(rst[j][0]);
            int py1 = dsu.find(rst[j][1]);
            if ((px == px1 && py == py1) || (px == py1 && py == px1)) {
                return false;
            }
        }
        dsu.merge(req[0], req[1]);
        return true;
    }
};
