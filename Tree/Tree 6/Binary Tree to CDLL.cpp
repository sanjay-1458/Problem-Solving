public:
    //Function to convert binary tree into circular doubly linked list.
    Node *fun(Node*curr,Node*&head,Node*&prev){
        if(!curr) return nullptr;
        fun(curr->left,head,prev);
        if(prev==nullptr){
            head=curr;
        }
        else{
            curr->left=prev;
            prev->right=curr;
        }
        prev=curr;
        fun(curr->right,head,prev);
        head->left=prev;
        prev->right=head;
        return head;
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        if(!root) return nullptr;
        Node *head=nullptr,*prev=nullptr;
        fun(root,head,prev);
        return head;
    }
