class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL) {
           cout << "called to NULL" << endl;
           return NULL;
       }
       if(root->data == n1 || root->data == n2) {
           cout << "Returning root("<< root->data <<") becuase root->data equals to either of n1 or n2"<< endl;
           return root;
       }
       
       Node* left = lca(root->left, n1, n2);
       Node* right = lca(root->right, n1, n2);
       
       if(left != NULL && right != NULL) {
           cout << "Returning root("<< root->data <<") becuase root's left and right both not null"<< endl;
           return root;
       }
       if(left == NULL && right != NULL) {
           cout << "Returning right("<< right->data <<") becuase root's left is null and right is not null"<< endl;
           return right;
       }
       if(left != NULL && right == NULL) {
           cout << "Returning left("<< left->data <<") becuase root's left is not null and right is null"<< endl;
           return left;
       }
       
       cout << "return null" <<endl;
       return NULL;
    }
};