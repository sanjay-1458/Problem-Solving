vector<pair<int,int>> fun(int x,int y){
    vector<pair<int,int>> ans;
    ans.push_back({x+1,y-2});
    ans.push_back({x+1,y+2});
    ans.push_back({x+2,y-1});
    ans.push_back({x+2,y+1});
    ans.push_back({x-1,y-2});
    ans.push_back({x-1,y+2});
    ans.push_back({x-2,y-1});
    ans.push_back({x-2,y+1});
    return ans;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int n=A,m=B;
    C--; D--; E--; F--;
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q; //{{x,y},dist}
    q.push({{C,D},0});
    int ans=-1;
    if(C==E && D==F) return 0;
    vis[C][D]=1;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        int x=node.first.first,y=node.first.second;
        // cout<<x<<" "<<y<<endl;
        int dist=node.second;
        vector<pair<int,int>> nbr=fun(x,y);
        for(auto it:nbr){
            int nx=it.first,ny=it.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                vis[nx][ny]=1;
                q.push({{nx,ny},dist+1});
                if(nx==E && ny==F){
                    return dist+1;
                }
            }
        }
    }
    return -1;
}
