class Solution {
    void bfs(vector<int> adj[],vector<int> &visited,int source){
        queue<int> q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(visited[x]==0){
                    visited[x]=1;
                    q.push(x);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adjList[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j && isConnected[i][j]==1){
                    adjList[i].push_back(j);
                }
            }
        }
        int provinces=0;
        vector<int> visited(n);
        for(int i=0;i<n;++i){
            if(visited[i]==0){
                provinces++;
                bfs(adjList,visited,i);
            }
        }
        return provinces;
    }
};
