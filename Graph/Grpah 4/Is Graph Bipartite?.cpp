class Solution {
    bool dfs(int source,vector<vector<int>>&graph,int vis[],int pclr,int p){
        if(pclr==1){
            vis[source]=2;
        }
        else{
            vis[source]=1;
        }
        for(auto  x:graph[source]){
            if(vis[x]==-1){
                if(dfs(x,graph,vis,vis[source],p)==false){
                    return false;
                }
            }
            else if(vis[x]==vis[source]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int vis[n];
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<n;++i){
            if(vis[i]==-1){
                if(dfs(i,graph,vis,2,-1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
