#include<bits/stdc++.h>

using namespace std;
/*
 Write code to partition alinked list around a value x, such that asll nodes less than x come before all nodes
 greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements
 less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to
 appear between the left and right partitions.

 EXAMPLE
 Input:  3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 */

struct Node {
    int data;
    Node* next;
};
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* partition(Node* head, int x) {
    cout << "start\n";
    Node* first = head;
    Node* end = head;

    if (head != NULL) {
        head = head->next;
        while (head != NULL) {
            
            Node* temp = head->next;
            if (head->data < x) {
                head->next = first;
                first = head;
            } else {
                end->next = head;
                head->next = NULL;
                end = head;
            }
            head = temp;
        }
    }
    return first;
}


Node* getList() {
    int value;
    cin >> value;
    Node* head = NULL;
    Node* end = NULL;

    while (value) {
        if (head == NULL) {
            head = new Node();
            head->data = value;
            head->next = NULL;
            end = head;
        } else {
            end->next = new Node();
            end = end->next;
            end->data = value;
            end->next = NULL;
        }
        cin >> value;
    }
    return head;
}
        

int main() {
    cout << "Enter the list values \n";
    Node* head = getList();
    printList(head);
    int value;
    cout << "Enter the partition value \n";
    cin >> value;
    printList(partition(head, value));
    return 0;
}