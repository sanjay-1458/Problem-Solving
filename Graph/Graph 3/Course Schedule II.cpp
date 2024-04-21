class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(int i=0;i<arr.size();++i){
            adj[arr[i][1]].push_back(arr[i][0]);
            indeg[arr[i][0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indeg.size();++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node]){
                if(indeg[x]==1){
                    q.push(x);
                }
                indeg[x]--;
            }
        }
        if(ans.size()==n){
            return ans;
        }
        else{
            return {};
        }
    }
};
