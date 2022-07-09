#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int ele){
        data=ele;
        left=NULL;
        right=NULL;
    }
};

node * build_tree(node *root)
{
    cout<<"enter data";
    int data;
    cin>>data;
    root=new node(data);

    //base condition
    if(data==-1)
        return NULL;


    cout<<"entering the left node";
    root->left=build_tree(root->left);
    cout<<"entering the right node";
    root->right=build_tree(root->right);
    return root;
}
void inorder(node* root,int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL)
    count++;
    inorder(root->right,count);

}


int main()
{
    node *root=NULL;
    root=build_tree(root);
    int count=0;
    inorder(root,count);
    cout<<count;


return 0;
}