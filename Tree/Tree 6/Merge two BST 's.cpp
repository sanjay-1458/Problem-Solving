 public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node*root,vector<int>&v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       vector<int> a,b;
       inorder(root1,a);
       inorder(root2,b);
       int n=a.size(),m=b.size();
       int i=0,j=0;
       while(i<n && j<m){
           if(a[i]<=b[j]){
               ans.push_back(a[i]);
               i++;
           }
           else{
               ans.push_back(b[j]);
               j++;
           }
       }
       while(i<n){
           ans.push_back(a[i]);
           i++;
       }
       while(j<n){
           ans.push_back(b[j]);
           j++;
       }
       return ans;
    }
