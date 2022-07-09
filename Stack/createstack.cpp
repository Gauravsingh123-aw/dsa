#include<iostream>
using namespace std;
class Stack{
    //properties of stack
    int *arr;
    int size;
    int top;
    //behaviour
    public:
    Stack(int size){
        this->size=size;
        arr= new int[size];
        top=-1;
    }
    void push(int);
    void pop();
    int peek();
    void printstack();
};
void  Stack::push(int ele){
    if(size-top>1)
    {
        top++;
        arr[top]=ele;
    }
    else {
        cout<<"stack overflow\n";
    }
}
void Stack:: pop(){
      if(top>=0)
      {
          top--;
      }
      else
      cout<<"Stack Underflow";
}
int  Stack:: peek(){
    int p;
    if(top==-1)
    cout<<"not possible";
    else
        p= arr[top];
    return p;

}
void Stack::printstack(){
        int i=top;
        while(i>=0){
            cout<<arr[i]<<" ";
            i--;
        }

}

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"peak element is "<<s.peek()<<endl;
    cout<<"Current Stack is"<<endl;
    s.printstack();
    cout<<"\ndeleting the top element.........\n";
    s.pop();
    // cout<<"Now the stack is";
    s.printstack();




return 0;
}