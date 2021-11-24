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

//function to insert node at beginning

void insertatbeg(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;
    if(head==NULL)
    {
        head=n;
    }
    else{
    head=n;
    head->next=temp;
    }

}
//function to insert node in middle
void insertatmid(node* &head,int val,int pos)
{
    node* n=new node(val);
    node* temp=head;
    node* p=head;
    int c=1;
    while(c!=pos)
    {
        temp=temp->next;
        p=p->next;
        c++;
    }
    p=temp->next;
    temp->next=n;
    n->next=p;

}
//function to insert a node at last

void insertatlast(node* &head,int val)
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
    cout<<"NULL"<<endl;
 }
int main()
{
    node* head=NULL;
    int n=1,value,choice;
    int pos;
    while(n>0)
    {
    cout<<"where do you want to insert the node in linkedlist"<<endl;
    cout<<"Press 1 to insert at beginning"<<endl;
    cout<<"Press 2 to insert at middle"<<endl;
    cout<<"press 3 to insert at last"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
        {
            cout<<"enter the value";
            cin>>value;
            insertatbeg(head,value);
        }
        break;
        case 2:
        {
            cout<<"enter the element and position";
            cin>>value>>pos;
            if(head==NULL)
                cout<<"not possible";
            insertatmid(head,value,pos);
        }
        break;
        case 3:
        {
            cout<<"enter the value";
            cin>>value;
            insertatlast(head,value);
        }
        break;
        default:
        cout<<"Wrong choice"<<endl;


    }
    display(head);
    cout<<"press 0 if you want to exit";
    cin>>n;
    }



return 0;
}