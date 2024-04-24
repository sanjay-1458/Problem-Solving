class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
       
        vector<pair<int,int>>adj[n];
         for(auto it:flights){
           adj[it[0]].push_back({it[1],it[2]});
         
         }
        vector<int>dis(n,INT_MAX);
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,src},0});
        dis[src]=0;
        while(!q.empty()){
            int cost=q.front().first.first;
            int node=q.front().first.second;
            int count=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(cost+it.second<dis[it.first] && count<=k){
                    dis[it.first]=cost+it.second;
                    q.push({{cost+it.second,it.first},count+1});
                }
            }
            
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        return dis[dst];
        
    }
};
