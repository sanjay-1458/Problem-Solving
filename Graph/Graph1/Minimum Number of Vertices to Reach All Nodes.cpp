class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0],v=edges[i][1];
            indeg[v]++;
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(indeg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
