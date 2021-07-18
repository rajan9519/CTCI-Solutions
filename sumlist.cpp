#include <bits/stdc++.h>

using namespace std;

/* 
Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
Output: 9 -> 1 -> 2.That is, 912.
*/

struct Node {
    int val;
    Node* next;
};

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node * getList() {
    int value;
    cin >> value;
    Node* head = NULL;
    Node* end = NULL;

    while (value != -1) {
        if (head == NULL) {
            head = new Node();
            head->val = value;
            head->next = NULL;
            end = head;
        } else {
            end->next = new Node();
            end = end->next;
            end->val = value;
            end->next = NULL;
        }
        cin >> value;
    }
    return head;
}

Node* SumList(Node* head1, Node* head2, int carry) {
    int sum =  carry;

    if (head1 != NULL) {
        sum += head1->val;
        head1 = head1->next;
    }
    if (head2 != NULL) {
        sum += head2->val;
        head2 = head2->next;
    }
    if (sum) {
        Node* res = new Node();
        res->val = sum % 10;
        res->next = SumList(head1, head2, sum / 10);
        return res;
    }
    return NULL;
}
int main() {
    cout << "Enter the first list: ";
    Node* head1 = getList();
    cout << "Enter the second list: ";
    Node* head2 = getList();

    Node* res = SumList(head1, head2, 0);
    printList(res);
    return 0;
}