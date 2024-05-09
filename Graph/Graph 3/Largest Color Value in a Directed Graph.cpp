class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(int i=0;i<(int)edges.size();++i){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){  
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            auto node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        int ans=0;
        if((int)topo.size()<n){
            return -1;
        }

        vector<vector<int>> v(n, vector<int>(26, 0));
        reverse(topo.begin(), topo.end());
        for(int i=0;i<n;++i){
            int node=topo[i];
            for(auto x : adj[node])
            {
                for(int i=0;i<26;++i)
                {
                    v[node][i] = max(v[node][i], v[x][i]);
                }
            }
            v[node][colors[node]-'a']++;
            ans = max(ans , v[node][colors[node]-'a']);
        }
        return ans;
    }
};
         
