class Solution {
    void dfs(int i,int j,vector<vector<int>>& vis){
        vis[i][j]=1;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        for(int k=0;k<4;++k){
            int newr=i+dr[k],newc=j+dc[k];
            if(newr>=0 && newr<vis.size() && newc>=0 && newc<vis[0].size() && !vis[newr][newc]){
                dfs(newr,newc,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'$'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> s;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(arr[i][j]=='O'){
                        s.push_back({i,j});
                    }
                }
                if(arr[i][j]=='X'){
                    
                    vis[i][j]=1;
                }
            }
        }
        for(int i=0;i<s.size();++i){
            int r=s[i][0],c=s[i][1];
            if(!vis[r][c]){
                dfs(r,c,vis);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if (!vis[i][j]) {
                    arr[i][j] = 'X';
                }
            }
        }
    }
};
