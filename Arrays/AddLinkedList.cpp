#include <iostream>
#include <vector>
#include "Main.cpp"

using namespace std;

Node<int> *addTwoNumbers(Node<int> *l1, Node<int> *l2)
{
    Node<int> *dummyHead = new Node<int>(0);
    Node<int> *curr = dummyHead;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->link = new Node<int>(sum % 10);
        curr = curr->link;
        l1 = l1 ? l1->link : nullptr;
        l2 = l2 ? l2->link : nullptr;
    }
    return dummyHead->link;
}

Node<int> *AddLinkedList(Node<int> *head1, Node<int> *head2)
{
    Node<int> *dummy = new Node<int>(0);
    Node<int> *temp = dummy;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry)
    {
        int num1 = head1 != NULL ? head1->data : 0;
        int num2 = head2 != NULL ? head2->data : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        Node<int> *newNode = new Node<int>(sum % 10);
        temp->link = newNode;
        temp = temp->link;
        head2 = head2 ? head2->link : nullptr;
        head1 = head1 ? head1->link : nullptr;
    }
    return dummy->link;
}

Node<int> *SwapPair(Node<int> *head)
{
    if (head == NULL || head->link == NULL)
        return head;
    Node<int> *temp = head->link;
    head->link = SwapPair(head->link->link);
    temp->link = head;

    return temp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node<int> *head1 = TakeInput();
        Node<int> *head2 = TakeInput();
        Node<int> *finalLinkedList = addTwoNumbers(head1, head2);
        printLinkedList(finalLinkedList);
    }
}
