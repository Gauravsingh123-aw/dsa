#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void create(node* &head,int val)
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

void deletion(node* &head,int val){
    node* temp=head;
    while(temp->next->data!=val)
    {

        temp=temp->next;
    }
    node* todelete=temp->next; // वो नोड todelete मे store करेंगे जिसे डिलीट करना है
    temp->next=temp->next->next;

    delete todelete;

}
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
    create(head,2);
    create(head,3);
    create(head,4);
    create(head,5);
    create(head,6);
    cout<<"this is your linkedlist-->>"<<endl;
    display(head);
    int value;
    cout<<"enter node you want to delete";
    cin>>value;
    deletion(head,value);
    cout<<"linkedlist after deletion is"<<endl;
    display(head);



return 0;
}