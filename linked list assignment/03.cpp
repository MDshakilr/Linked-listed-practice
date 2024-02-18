/*Task 3:
Learn to reverse the linked list in-place. Implement a function that changes the order of nodes
in the list.

Sample Input:
- Reverse the linked list:5->25->20

Sample Output:
Linked List: 20 -> 25 -> 5
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

Node* reverseList(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
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
    head = addBeginning(head, 20);
    head = addBeginning(head, 25);
    head = addBeginning(head, 5);
    cout << "Original Linked List: ";
    printList(head);
    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    deleteList(head);

    return 0;
}
