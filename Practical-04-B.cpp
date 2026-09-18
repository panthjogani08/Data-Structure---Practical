
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for(char c : postfix)
    {
        if(c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if(c == '+')
                result = a + b;
            else if(c == '-')
                result = a - b;
            else if(c == '*')
                result = a * b;
            else if(c == '/')
                result = a / b;

            s.push(result);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}

