 /*Task 5:
Build on your knowledge by merging two sorted linked lists into one sorted list. Implement a
function to do this while updating the head pointers correctly.

Sample Input:
- Merge two sorted lists: List A: 5 -> 10, List B: 7 -> 12.

Sample Output:
Merged List: 5 -> 7 -> 10 -> 12

*/#include <iostream>
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

Node* mergeSortedLists(Node* list1, Node* list2)
{

    Node* dummy = createNode(0);
    Node* current = dummy;


    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }


    if (list1 != nullptr)
    {
        current->next = list1;
    }
    else
    {
        current->next = list2;
    }
    Node* mergedList = dummy->next;
    delete dummy;

    return mergedList;
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
    Node* listA = createNode(5);
    listA->next = createNode(10);

    Node* listB = createNode(7);
    listB->next = createNode(12);
    Node* mergedList = mergeSortedLists(listA, listB);
    cout << "Merged List: ";
    printList(mergedList);
    deleteList(listA);
    deleteList(listB);
    deleteList(mergedList);

    return 0;
}

