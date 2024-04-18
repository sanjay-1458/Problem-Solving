public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<pair<int,int>,int>> q; // {{x,y},dist}
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    for(int i=0;i<n;++i){
	        for(int j=0;j<m;++j){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                grid[i][j]=-1;
	                ans[i][j]=0;
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
	        int dist=node.second;
	        for(int i=0;i<4;++i){
	            int nr=dr[i]+x;
	            int nc=dc[i]+y;
	            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=-1){
	                ans[nr][nc]=dist+1;
	                grid[nr][nc]=-1;
	                q.push({{nr,nc},dist+1});
	            }
	        }
	    }
	    return ans;
