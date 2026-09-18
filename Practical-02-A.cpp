#include <iostream>
using namespace std;

int main()
{
    int n, a[10];
    
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int *p = &a[n-1];

    cout << "Array elements in reverse order: ";

    for(int i = 0; i < n; i++)
    {
        cout << *p << " ";
        p--;
    }

    return 0;
}