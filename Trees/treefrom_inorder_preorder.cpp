//In this program we are constructing a tree from inorder and preorder sequences
// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
// O(n^2)
class Solution{
    public:
    int findpos(int in[],int element,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            return i;
        }
        return -1;
    }  //although this function can be optimized using map function
    Node * solve(int in[],int pre[],int &preorderindex,int start,int end,int n)
    {
        // base case
        if(preorderindex>=n || start>end)
        {
            return NULL;
        }
        //preorder ka 1st element pick karke usko root bana denge
        int element=pre[preorderindex];
        preorderindex++;
        Node *root=new Node(element);
        int position=findpos(in,element,n);

        // ab inorder ke pos se left call aur right call maar denge

        root->left=solve(in,pre,preorderindex,start,position-1,n);

        root->right=solve(in,pre,preorderindex,position+1,end,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        Node * ans=solve(in,pre,preorderindex,0,n-1,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends