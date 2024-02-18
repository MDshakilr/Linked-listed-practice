/*Task 2:
Extend your linked list operations. Implement functions to insert a node after a specific value
or at a given position and to delete nodes with a given value or at a given position.

Sample Input:
- Insert 25 after 10.
- Delete the node with the value 10.
- Insert 20 at position 2.
- Delete the node at position 3.
Sample Output:
Linked List: 5 -> 25 -> 20
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* createNode(int value)
{
    Node* newNode = new Node;
    if (newNode != nullptr)
    {
        newNode->data = value;
        newNode->next = nullptr;
    }
    return newNode;
}
Node* addBeginning(Node* head, int value)
{
    Node* newNode = createNode(value);
    if (newNode != nullptr)
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}
void addEnd(Node* head, int value)
{
    Node* newNode = createNode(value);
    if (newNode != nullptr)
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = newNode;
    }
}
void insertAfterValue(Node* head, int targetValue, int valueToInsert)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == targetValue)
        {
            Node* newNode = createNode(valueToInsert);
            if (newNode != nullptr)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
        }
        current = current->next;
    }
}
void deleteNodeWithValue(Node*& head, int targetValue)
{
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == targetValue)
        {
            if (prev == nullptr)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
}
void insertPosition(Node*& head, int position, int valueToInsert)
{
    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    Node* newNode = createNode(valueToInsert);
    if (newNode != nullptr)
    {
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != nullptr; ++i)
            {
                current = current->next;
            }

            if (current != nullptr)
            {
                newNode->next = current->next;
                current->next = newNode;
            }
            else
            {
                cout << "Invalid position.\n";
                delete newNode;
            }
        }
    }
}
void deletePosition(Node*& head, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* prev = nullptr;

        for (int i = 1; i < position && current != nullptr; ++i)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            prev->next = current->next;
            delete current;
        }
        else
        {
            cout << "Invalid position.\n";
        }
    }
}
void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next != nullptr)
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}
void deleteList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main()
{
    Node* head = nullptr;
    head = addBeginning(head, 5);
    addEnd(head, 10);
    addEnd(head, 15);
    insertAfterValue(head, 10, 25);
    deleteNodeWithValue(head, 10);
    insertPosition(head, 2, 20);
    deletePosition(head, 3);
    cout << "Linked List: ";
    printList(head);

    deleteList(head);

    return 0;
}
