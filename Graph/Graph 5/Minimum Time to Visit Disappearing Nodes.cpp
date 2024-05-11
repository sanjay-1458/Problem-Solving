class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
	
        for(int i=0;i<(int)edges.size();++i){
            int u=edges[i][0],v=edges[i][1],t=edges[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        vector<int> dist(n, 1e9);
        dist[0]=0;
        set<pair<int,int>> st;
        st.insert({0,0});
        
        while(!st.empty()){
            auto node = *st.begin();
            st.erase(st.begin());
            
            int cost = node.first;
            int src = node.second;
            
            for(auto x: adj[src]){
                int u = x.first;
                int dis = x.second;
                
                if (dis+cost < dist[u] && dis+cost < disappear[u]){
                    if (dist[u] != 1e8){
                        st.erase({dist[u], u});
                    }
                    dist[u] = dis+cost;
                    st.insert({dist[u], u});
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(0);
        
        for(auto i=1;i<n;++i){
            if (dist[i] < disappear[i]){
                ans.push_back(dist[i]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};
