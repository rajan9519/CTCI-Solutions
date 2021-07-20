#include <bits/stdc++.h>

using namespace std;

/*
    Palindrom: Implement a function to check if a linked list is a palindrome.
*/

struct Node {
    int data;
    Node *next;
};


Node* getList() {
    int value;
    cin >> value;
    Node* head = NULL;
    Node* end = NULL;

    while (value != -1) {
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

int length(Node *head) {
    int len = 0;
    Node *curr = head;
    while (curr != nullptr) {
        len++;
        curr = curr->next;
    }
    return len;
}

bool isPalindrome(Node *head,Node* &back, int len) {
    if (len == 0) {
        back = head;
        return true;
    } else if (len == 1) {
        back = head->next;
        return true;
    }
    bool res = isPalindrome(head->next, back, len-2);
    res = res && (head->data == back->data);
    back = back->next;
    return res;
}

bool palindromeMaster(Node *head) {
    int len = length(head);
    Node *back = nullptr;
    return isPalindrome(head, back, len);
}

int main() {
    Node* head = getList();
    bool res = palindromeMaster(head);
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}