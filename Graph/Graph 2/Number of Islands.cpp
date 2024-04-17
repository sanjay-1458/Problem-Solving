class Solution {
    void bfs(int r,int c,vector<vector<char>>& grid){
        int n=grid.size(),m=grid[0].size();
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'){
                    grid[nr][nc]='0';
                    q.push({nr,nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
