
// Recursion - Brute Force
class Solution {
    void dfs(int node,int ulp,vector<int> adj[],vector<vector<int>>&ans){
        for(auto x:adj[node]){
            if(ans[x].empty() || ans[x].back()!=ulp)
                ans[x].push_back(ulp);
            dfs(x,ulp,adj,ans);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<vector<int>> ans(n,vector<int>());
        for(int i=0;i<n;++i){
            dfs(i,i,adj,ans);
        }
        return ans;
    }
};
