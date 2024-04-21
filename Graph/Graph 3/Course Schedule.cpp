class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(int i=0;i<arr.size();++i){
            adj[arr[i][1]].push_back(arr[i][0]);
            indeg[arr[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto x:adj[node]){
                if(indeg[x]==1){
                    q.push(x);
                }
                indeg[x]--;
            }
        }
        if(cnt==n){
            return true;
        }
        else{
            return false;
        }
    }
};
