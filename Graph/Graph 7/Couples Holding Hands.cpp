class DSU{
    vector<int> rank;
    public:
    vector<int> parent;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    bool merge(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv) return false;
        parent[pu]=pv;
        // if(rank[pu]<rank[pv]){
        //     parent[pu]=parent[pv];
        // }
        // else if(rank[pu]>rank[pv]){
        //     parent[pv]=parent[pu];
        // }
        // else{
        //     parent[pv]=parent[pu];
        //     rank[pu]++;
        // }
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row){
        int n=row.size();
        if(n==0) return 0;
        DSU dsu(n);
        for (int i=0;i<n;i+=2){
            dsu.parent[row[i]]=row[i];
            dsu.parent[row[i+1]]=row[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (dsu.merge(i, i + 1))
                ans++;
        }
        
        return ans;
    }
};
