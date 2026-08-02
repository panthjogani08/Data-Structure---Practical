#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, pos, item, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray elements are: ";                // (Traversal)
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter position to insert: ";                   // (Insertion)
    cin >> pos;
    cout << "Enter element to insert: ";
    cin >> item;

    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = item;
    n++;

    cout << "\nArray after insertion: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter position to delete: ";               //(Deletion)
    cin >> pos;

    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "\nArray after deletion: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter element to search: ";               //(Serch)
    cin >> key;

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1;
            return 0;
        }
    }

    cout << "Element not found.";

    return 0;
}