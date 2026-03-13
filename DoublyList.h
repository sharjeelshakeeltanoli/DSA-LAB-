#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include<iostream>
using namespace std;

template<class ItemType>
struct dnode
{
    ItemType info;
    dnode* next;
    dnode* prev;
};

template<class ItemType>
class DoublyList
{
private:
    dnode<ItemType>* listptr;

public:

    DoublyList()
    {
        listptr = NULL;
    }

    void insertSorted(ItemType value)
    {
        dnode<ItemType>* newNode = new dnode<ItemType>;
        newNode->info = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // if list empty
        if (listptr == NULL)
        {
            listptr = newNode;
            return;
        }

        // insert at start
        if (value < listptr->info)
        {
            newNode->next = listptr;
            listptr->prev = newNode;
            listptr = newNode;
            return;
        }

        dnode<ItemType>* current = listptr;

        // move until correct position
        while (current->next != NULL && current->next->info < value)
        {
            current = current->next;
        }

        newNode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }

    void deleteItem(ItemType value)
    {
        dnode<ItemType>* current = listptr;

        while (current != NULL && current->info != value)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }

        if (current->prev != NULL)
            current->prev->next = current->next;
        else
            listptr = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;

        delete current;
    }

    void searchItem(ItemType value)
    {
        dnode<ItemType>* current = listptr;

        while (current != NULL)
        {
            if (current->info == value)
            {
                cout << "Value found" << endl;
                return;
            }

            current = current->next;
        }

        cout << "Value not found" << endl;
    }

    void displayForward()
    {
        dnode<ItemType>* current = listptr;

        cout << "Forward: ";

        while (current != NULL)
        {
            cout << current->info << " <-> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    void displayBackward()
    {
        if (listptr == NULL)
        {
            cout << "List empty" << endl;
            return;
        }

        dnode<ItemType>* current = listptr;

        while (current->next != NULL)
        {
            current = current->next;
        }

        cout << "Backward: ";

        while (current != NULL)
        {
            cout << current->info << " <-> ";
            current = current->prev;
        }

        cout << "NULL" << endl;
    }
};

#endif