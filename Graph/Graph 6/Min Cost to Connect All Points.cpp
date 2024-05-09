class DSU{
    vector<int> rank;
    vector<int> parent;
    public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }
    int findUP(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUP(parent[node]);
    }
    void Union(int a,int b){
        int ulp_a=findUP(a);
        int ulp_b=findUP(b);
        if(ulp_a==ulp_b){
            return;
        }
        if(rank[ulp_a]<rank[ulp_b]){
            parent[ulp_a]=parent[ulp_b];
        }
        else if(rank[ulp_b]<rank[ulp_a]){
            parent[ulp_b]=parent[ulp_a];
        }
        else{
            parent[ulp_b]=parent[ulp_a];
            rank[ulp_a]++;
        }
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;++i){
            mp[i]=points[i];
        }
        int ans=0;
        vector<pair<int,pair<int,int>>> vp; // wt,{nodes}
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vp.push_back({wt,{i,j}});
            }
        }
        sort(vp.begin(),vp.end());
        DSU dsu(n);
        for(auto x:vp){
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            if(dsu.findUP(u)!=dsu.findUP(v)){
                ans+=wt;
                dsu.Union(u,v);
            }
        }
        return ans;
    }
};
