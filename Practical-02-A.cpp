#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;

    cout<<"enter no of element : ";
    cin >> n;

    int *a = (int*)malloc(n * sizeof(int));

    cout<<"enter element : ";

    if (a == NULL) {
        cout << "Memory Allocation Failed";
        return 0;
    }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout<<"Array Elements in Reverse Order : ";

    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << " ";

    free(a);

    return 0;
}