/*Task 4:
Implement a function to check if a linked list contains a cycle.

Sample Input:
- Create a linked list with a cycle.

Sample Output:
Has Cycle: Yes
Cycle Start Node: 10
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
Node* addToBeginning(Node* head, int value)
{
    Node* newNode = createNode(value);
    if (newNode != nullptr)
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}
bool hasCycle(Node* head, Node*& startNode)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {

            startNode = head;
            while (startNode != slow)
            {
                startNode = startNode->next;
                slow = slow->next;
            }
            return true;
        }
    }


    return false;
}

int main()
{

    Node* head = nullptr;
    head = addToBeginning(head, 20);
    head = addToBeginning(head, 30);
    head = addToBeginning(head, 10);
    head = addToBeginning(head, 40);

    head->next->next->next->next = head->next;

    Node* startNode = nullptr;
    bool hasCycleResult = hasCycle(head, startNode);


    if (hasCycleResult)
    {
        cout << "Has Cycle: Yes" << endl;
        cout << "Cycle Start Node: " << startNode->data << endl;
    }
    else
    {
        cout << "Has Cycle: No" << endl;
    }

    return 0;
}

