
#include <iostream>
using namespace std;

void callValue(int x)
{
    x = 20;
    cout << "Value inside function = " << x << endl;
}

void callReference(int *x)
{
    *x = 20;
    cout << "Value inside function = " << *x << endl;
}

int main()
{
    int a = 10;
    int b = 10;

    cout << "Call by Value" << endl;
    cout << "Before = " << a << endl;
    callValue(a);
    cout << "After = " << a << endl;

    cout << endl;

    cout << "Call by Reference" << endl;
    cout << "Before = " << b << endl;
    callReference(&b);
    cout << "After = " << b << endl;

    return 0;
}

