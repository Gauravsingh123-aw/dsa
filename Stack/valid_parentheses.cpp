#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool matches(char top,char exp)
{
    if((top=='(' && exp==')' )|| (top=='{'&& exp=='}')|| (top=='[' && exp==']'))
    {
        return true;
    }
}
int main()
{
    stack <char> s;
    string exp;
    cout<<"enter your expression";
    cin>>exp;
    for (int i = 0; i < exp.size(); i++)
    {
        //**for opening bracket
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            s.push(exp[i]);
        }

        //**for closing bracket
        else{
            if(!s.empty())
            {
            if(matches(s.top(),exp[i]))
            {
                s.pop();
            }  }

            else{
                return false;
            }
        }
    }
    if(s.empty())
     cout<<"matched";
    else
     cout<<"invalid expression";


return 0;
}

