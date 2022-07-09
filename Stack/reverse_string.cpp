#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<char> s;
    string a;
    cout<<"enter the string";
    cin>>a;
    for(int i=0;i<a.size();i++){
        s.push(a[i]);
    }
    string ans="";
    while(!s.empty()){
        ans=ans+s.top();
        s.pop();
    }
    cout<<"reversed string is->>"<<ans;

return 0;
}
//** Time complexity is O(n)s``