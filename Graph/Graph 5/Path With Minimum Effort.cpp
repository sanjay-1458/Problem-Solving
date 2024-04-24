class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        // queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int row=it.second.first;
            int wt=it.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1){
                return wt;
            }
            for(int i=0;i<4;++i){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m ){
                    int diff=max(abs(heights[row][col]-heights[newr][newc]),wt);
                    if(diff<dist[newr][newc]){
                        dist[newr][newc]=diff;
                        q.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};
