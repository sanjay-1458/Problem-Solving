class Solution {
public:
    int dijkstra(vector<vector<pair<int,int>>> &adj,vector<int>&distance,int node,int threshold){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node});
        distance[node]=0;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int dis=node.first;
            int src=node.second;
            for(auto it:adj[src]){
                if(dis+it.second< distance[it.first]){
                 distance[it.first]=dis+it.second;
                    pq.push({dis+it.second,it.first});
                }
            }
        }
        int cnt=0;
        for(auto &it:distance){
            if(it<=threshold){
                if(it==0)continue;
                cnt++;
            }
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<(int)edges.size();++i){
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            vector<int> distance(n,1e9);
            ans[i]=dijkstra(adj,distance,i,distanceThreshold);
        }
        vector<int> nums=ans;
        sort(nums.begin(),nums.end());
        int x=nums[0];
        for(int i=n-1;i>=0;--i){
            if(ans[i]==x)return i;
        }
        return 0;
    }
};
