//deleting middle element from stack using recursion
#include<iostream>
#include<stack>
using namespace std;
void solve(stack <int> & s,int n,int count)
{
    //base condition
    if(count==n/2){
        s.pop();
        return;
    }
    int ele=s.top();
    s.pop();
    solve(s,n,count+1);
    s.push(ele);
}
int main()
{
    stack <int> s;
    int n;
    cin>>n; //taking size
    for (int i = 0; i < n; i++)  //**taking stack as input
    {
        int ele;
        cin>>ele;
        s.push(ele);
    }
    int count=0;
    //**funtion to solve the problem
    solve(s,n,count);


return 0;
}