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

// Helper function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to create a linked list
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

// Recursive function to create sum of linked list 
// from left to right
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

// Helper function to find the length of the linked list
int length(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Helper function to pad the linked list with 0's
Node* pad(Node* head, int len) {
    while (len) {
        Node* tmp = new Node();
        tmp->val = 0;
        tmp->next = head;
        head = tmp;
        len--;
    }
    return head;
}

// Recursive funtion to find the sum of linked list
// from right to left, assuming the lists are of equal length
// carry is passed by reference to get in the caller function
Node* helperSum(Node* head1, Node* head2, int &carry) {
    int sum = head1->val + head2->val;

    if(head1->next != NULL) {
        Node* res = helperSum(head1->next, head2->next, carry);
        sum += carry;
        Node* tmp = new Node();
        tmp->val = sum % 10;
        tmp->next = res;
        carry = sum / 10;
        return tmp;
    } else {
        Node* tmp = new Node();
        sum += carry;
        tmp->val = sum % 10;
        carry = sum / 10;
        return tmp;
    }
}

//  Master function to calculate sum of linked lists
// from right to left
Node* SumList1(Node* head1, Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    // pad the linked lists with 0's to have equal length
    if (len1 > len2) {
        head2 = pad(head2, len1 - len2);       
    } else {
        head1 = pad(head1, len2 - len1);
    }
    // find the sum of the linked lists from right to left
    int carry = 0;
    Node* res = helperSum(head1, head2, carry);

    if (carry) {
        Node* tmp = new Node();
        tmp->val = carry;
        tmp->next = res;
        res = tmp;
    }
    return res;
}
int main() {
    cout << "Enter the first list: ";
    Node* head1 = getList();
    cout << "Enter the second list: ";
    Node* head2 = getList();


    Node* res = SumList(head1, head2, 0);
    cout << "Sum from left to right node: ";
    printList(res);

    Node* res1 = SumList1(head1, head2);
    cout << "Sum from right to left node: ";
    printList(res1);
    return 0;
}