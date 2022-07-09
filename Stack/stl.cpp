#include<iostream>
#include<stack>
using namespace std;
void printstack(stack<int> s){
    if(s.empty())
        return;
    else
    {
        int x=s.top();
        s.pop();
        cout<<x<<" ";
        printstack(s);
    }
    //or we can do this by
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
}
int main()
{
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    printstack(s);
    //?is stack empty


return 0;
}