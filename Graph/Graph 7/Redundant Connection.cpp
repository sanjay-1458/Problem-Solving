class DSU{
    vector<int> rank;
    vector<int> parent;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void merge(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=parent[pv];
        }
        else if(rank[pu]>parent[pv]){
            parent[pv]=parent[pu];
        }
        else{
            parent[pv]=parent[pu];
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int r1=-1,r2=-1;
        DSU dsu(edges.size()+1);
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0],v=edges[i][1];
            if(dsu.find(u)==dsu.find(v)){
                r1=u;r2=v;
            }
            else{
                dsu.merge(u,v);
            }
        }
        return {r1,r2};
    }
};
