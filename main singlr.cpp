#include<iostream>
#include "DoublyList.h"
using namespace std;

int main()
{
    DoublyList<int> list;

    int choice;
    int value;

    do
    {
        cout << "\n1 Insert\n";
        cout << "2 Delete\n";
        cout << "3 Search\n";
        cout << "4 Display Forward\n";
        cout << "5 Display Backward\n";
        cout << "6 Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertSorted(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.deleteItem(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.searchItem(value);
            break;

        case 4:
            list.displayForward();
            break;

        case 5:
            list.displayBackward();
            break;
        }

    } while (choice != 6);

    return 0;
}