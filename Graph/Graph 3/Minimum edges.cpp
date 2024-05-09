void fun(int node,int& dst,set<int> curr[],vector<int>adj[],int &ans,int cur,vector<int>&vis){
        if(node==dst){
            ans=min(ans,cur);
            return;
        }
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==0){
                if(curr[node].find(x)!=curr[node].end()){
                    fun(x,dst,curr,adj,ans,cur,vis);
                }
                else{
                    fun(x,dst,curr,adj,ans,cur+1,vis);
                }
            }
        }
        vis[node]=0;
    }
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<int> adj[n+1];
            set<int> curr[n+1];
            for(int i=0;i<(int)edges.size();++i){
                int u=edges[i][0],v=edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                curr[u].insert(v);
            }
            int ans=1e9;
            vector<int> vis(n+1,0);
            fun(src,dst,curr,adj,ans,0,vis);
            if(ans==1e9) return -1;
            return ans;
        }
