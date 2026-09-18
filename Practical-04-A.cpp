
#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if(c == '+' || c == '-')
        return 1;

    if(c == '*' || c == '/')
        return 2;

    return 0;
}

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix: ";
    cin >> infix;

    for(char c : infix)
    {
        if(isalnum(c))
            postfix += c;

        else if(c == '(')
            s.push(c);

        else if(c == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
        }

        else
        {
            while(!s.empty() &&
                  s.top() != '(' &&
                  priority(s.top()) >= priority(c))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix = " << postfix;

    return 0;
}
