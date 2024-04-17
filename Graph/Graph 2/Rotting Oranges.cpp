class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int one=0;
        queue<pair<pair<int,int>,int>> q; // {{x,y},time}
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    one++;
                }
            }
        }
        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.first.first;
            int y=node.first.second;
            int time=node.second;
            ans=time;
            for(int i=0;i<4;++i){
                int nx=dr[i]+x;
                int ny=dc[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    one--;
                    grid[nx][ny]=2;
                    q.push({{nx,ny},time+1});
                }
            }
        }
        if(one==0) return ans;
        else return -1;
    }
};
