#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&mystack,int x )
{	//base condition
	if(mystack.empty())
	{
		mystack.push(x);
		return ;
	}
	int ele=mystack.top();
	mystack.pop();
	solve(mystack,x);
	mystack.push(ele);
}


int main()
{
    stack<int> myStack;
    int x=9;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    solve(myStack,x);
	while (!myStack.empty())
    {
        cout<<myStack.top();
        myStack.pop();
    }
return 0;

}