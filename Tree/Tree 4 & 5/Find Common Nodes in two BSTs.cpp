public:
    //Function to find the nodes that are common in both BST. 
    void inorder(Node*root,unordered_map<int,int>&mp){
        if(!root) return;
        inorder(root->left,mp);
        mp[root->data]++;
        inorder(root->right,mp);
    }
    void inorder(Node*root,unordered_map<int,int>&mp,vector<int>&ans){
        if(!root) return;
        inorder(root->left,mp,ans);
        if(mp.find(root->data)!=mp.end()){
            ans.push_back(root->data);
        }
        inorder(root->right,mp,ans);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     unordered_map<int,int> mp;
     vector<int> ans;
     inorder(root1,mp);
     
     inorder(root2,mp,ans);
     return ans;
    }
