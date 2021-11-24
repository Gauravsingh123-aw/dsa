#include<iostream>
using namespace std;

//creating a node using class

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

//function to insert a node at last

void createnode(node* &head,int val)
{
    node* n= new node(val);
    node* temp=head;
    if(head==NULL)
        head=n;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
 //function to display the linkedlist

 void display(node* &head)
 {
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
    }
    cout<<"NULL";
 }
int main()
{
    node* head=NULL;
    int n,value;
    cout<<"How many element you want to store in linked list";
    cin>>n;
    while(n--)
    {
        cout<<"Enter the value";
        cin>>value;
        createnode(head,value);
    }



    display(head);

return 0;
}