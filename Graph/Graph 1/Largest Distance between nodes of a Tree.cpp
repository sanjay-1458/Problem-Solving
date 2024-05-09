// Recursion - Brute Force
int fun(int node, int &maxi, vector<int> adj[]) {
    int x = 0;
    int ans = 0;
    for (auto e : adj[node]) {
        x += fun(e, maxi, adj);
        ans = max(ans, fun(e, maxi, adj));
    }
    maxi = max(maxi, x);
    return 1 + ans;
}

int Solution::solve(vector<int> &A) {
    int x = 0;
    vector<int> adj[A.size()];
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == -1) {
            x = i;
            continue;
        }
        int u = A[i];
        int v = i;
        adj[u].push_back(v);
    }
    int maxi = 0;
    fun(x, maxi, adj);
    if(adj[x].size()>2){
        return maxi-1;
    }
    return maxi;
}
