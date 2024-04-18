bool touch(int i,int j,int r,vector<int>&x,vector<int>&y){
    int n=x.size();
    for(int l=0;l<n;++l){
        int xi=x[l],yi=y[l];
        int dist=(xi-i)*(xi-i)+(yi-j)*(yi-j);
        if(dist>=r*r) return true;
    }
    return false;
}

string Solution::solve(int n, int m, int N, int r, vector<int> &X, vector<int> &Y) {
    vector<vector<int>> vis(n+2,vector<int>(m+2,0));
    queue<pair<int,int>> q; // {x,y}
    // check 0,0 for X,Y
    if(touch(0,0,r,X,Y)) return "NO";
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        int x=node.first,y=node.second;
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                int nx=x+i,ny=y+j;
                if(nx>=0 && nx<=n && ny>=0 && ny<=m && vis[nx][ny]==0){
                    if(touch(nx,ny,r,X,Y)){
                    }
                    else{
                        q.push({nx,ny});
                        if(nx==n && ny==m) return "YES";
                    }
                    vis[nx][ny]=1;
                }
            }
        }
    }
    return "NO";
}
