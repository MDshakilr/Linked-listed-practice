
/*Task 1:
Create a basic singly linked list structure in C. Define a structure for a node that holds an
integer value and a pointer to the next node. Implement functions to add nodes at the
beginning and end of the list.

Sample Input:
- Add 5 to the beginning.
- Add 10 to the end.
- Add 15 to the end.

Sample Output:
Linked List: 5 -> 10 -> 15
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
void  deleteList(Node* head)
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
    cout << "Linked List: ";
    printList(head);

    deleteList(head);
    return 0;
}
