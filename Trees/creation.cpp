#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node * left;
    node * right;
    public:
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }};
    node* buildtree(node * root){
        cout<<"enter data";
        int data;
        cin>>data;
        root=new node(data);
        if(data==-1)
            return NULL;
        cout<<"enter data to be inserted in left of  "<<data<<endl;
        root->left= buildtree(root->left);
        cout<<"enter data to be inserted in right of "<<data<<endl;
        root->right=buildtree(root->right);
        return root;
    }
    void levelordertraversal(node *root)        //**also known as bfs
    {
        queue<node*> q;
        //pehle 1st level ka data insert karte hai queue me
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            node* temp=q.front();
            q.pop();
            if(temp==NULL){    //purana level complete ho chuka hai
                cout<<endl;
                if(!q.empty())//queue still have some child nodes
                q.push(NULL);
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }


    }
void inorder(node* root)
{
    // **base condition
    if(root== NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    //base case
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void buildfromlevelordertraversal(node *root)
{
    queue<node *> q;
    cout<<"enter data for root";
    int rdata;
    cin>>rdata;
    root=new node(rdata);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"enter data for left node"<<root->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(leftdata);
        }
        cout<<"enter data for right node"<<root->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(rightdata);
        }
    }
}
int main()
{
    node *root=NULL;
    // root=buildtree(root);
    // //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelordertraversal(root);
    // cout<<"printing inodertraversal .....";
    // inorder(root);
    // cout<<endl;
    // cout<<"printing preorder.....";
    // preorder(root);
    // cout<<endl;
    // cout<<"printing postorder traversal...";
    // postorder(root);

    buildfromlevelordertraversal(root);
return 0;
}