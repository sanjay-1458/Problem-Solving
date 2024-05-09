public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> indeg(v,0);
        queue<int> q;
        for(int i=0;i<v;++i){
            for(auto x:adj[i]){
                indeg[x]++;
            }
        }
        for(int i=0;i<v;++i){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        return (int)topo.size()!=v;
    }
