#include<iostream>
using namespace std;

class node{
 public:
   int data;
   node*left;
   node*right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void inorder(node*root){
    if(!root) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//note: inorder of bst is sorted
node*insertIntoBst(node*root,int k){
    if(root==NULL) {
        root=new node(k);
        return root;
    }

    if(k>root->data){
        root->right=insertIntoBst(root->right,k);
    }
    else{
        root->left=insertIntoBst(root->left,k);
    }
    return root;
}
void takeInput(node*&root){
    int data;cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}

int main(){

node*root=new node(5);
cout<<"Enter data to create BST:"<<endl;
takeInput(root);
cout<<"Printing the BST"<<endl;
inorder(root);

return 0;
}