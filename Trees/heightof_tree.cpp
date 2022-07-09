#include<iostream>
#include<queue>
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

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                //queue still has some child ndoes
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int height(node *root)
{
    //base case
    if(root==NULL)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;


}
int main()
{
// calculate the height of left and right subtree and add 1 for root node with recursion.....
//              1
//            /   \
//           2     3
//          / \   / \
//         4   5 6   8
//                   /
//                  10
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

node * root=NULL;
root=buildTree(root);
levelOrderTraversal(root);
cout<<"height of tree is  ::"<<height(root);



return 0;
}

//Time Complexity=O(n)
//Space Complexity= O(height of tree)  worst case(skew tree)-O(n)
