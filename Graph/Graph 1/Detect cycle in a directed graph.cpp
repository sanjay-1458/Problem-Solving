bool dfs(int node,vector<int> adj[],vector<int> &pathvis,vector<int>&vis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(dfs(x,adj,pathvis,vis)==true){
                    return true;
                }
            }
            else if(pathvis[x]){
                return true;
            }
        }
        pathvis[node]=0;
        vis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int v, vector<int> adj[]) {
        
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        for(int i=0;i<v;++i){
            if(!vis[i]){
                if(dfs(i,adj,pathvis,vis)==true){
                    return true;
                }
            }
        }
        return false;
        // code here
    }
