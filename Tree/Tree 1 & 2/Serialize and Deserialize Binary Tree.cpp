class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    int num(string &data, int &idx){
        string s = "";
        while(data[idx] != ','){
            s += data[idx];
            idx++;
        }
        idx++;
        if(s == "#") return INT_MIN;
        return stoi(s);
    }

    TreeNode* solve(string &data, int &idx){
        int val = num(data,idx);
        TreeNode* ans =( val == INT_MIN) ? NULL : new TreeNode(val);
        if(ans){
            ans->left = solve(data,idx);
            ans->right = solve(data,idx);
        } 
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return solve(data,idx);
    }
};
