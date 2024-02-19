/*
Task 2:
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
    Node *next;
};

Node *head = nullptr;
void firstNode(int data)
{
    head = new Node;
    head->data = data;
    head->next = nullptr;
}
void addNode(int data)
{
    Node *ptr;
    ptr = head;
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void addNodeposition(int position, int data)
{
    Node *ptr = head;
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    int i = 0;
    while (i != position - 1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void deletePosition(int position)
{
    if (head->next == nullptr)
    {
        head = nullptr;
    }
    else
    {
        Node *ptr = head;
        int i = 0;
        while (i != position - 1)
        {
            ptr = ptr->next;
            i++;
        }
        ptr->next = ptr->next->next;
    }
}
void printNode()
{
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << "->";
        }
        temp = temp->next;
    }
}

int main()
{
    firstNode(5);
    addNode(10);
    addNode(15);
    printNode();
    cout<<endl;
    addNodeposition(2, 25);
    deletePosition(1);
    addNodeposition(2, 20);
    deletePosition(3);
    printNode();


    return 0;
}
