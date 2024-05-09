class DSU{
    vector<int> rank;
    vector<int> parent;
    public:
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
    void merge(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=parent[pv];
        }
        else if(rank[pu]>rank[pv]){
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n),bob(n);
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        int ans=0;
        int a=n,b=n;
        for(int i=0;i<edges.size();++i){
            int type=edges[i][0],u=edges[i][1],v=edges[i][2];
            if(type==3){
                if(bob.find(u)==bob.find(v)){
                    ans++;
                }
                else{
                    a--;
                    b--;
                    bob.merge(u,v);
                    alice.merge(u,v);
                }
            }
            else if(type==2){
                if(bob.find(u)==bob.find(v)){
                    ans++;
                }
                else{
                    b--;
                    bob.merge(u,v);
                }
            }
            else{
                if(alice.find(u)==alice.find(v)){
                    ans++;
                }
                else{
                    a--;
                    alice.merge(u,v);
                }
            }
        }
        if(a==1 && b==1) return ans;
        else return -1;
    }
};
