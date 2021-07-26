#include <bits/stdc++.h>

using namespace std;

/*
    Minimal Tree: Given a sorted (increasing order) array with unique integer elements, 
    write an algorithm to create a binary search tree with minimal height.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    postorder(root->left);
    postorder(root->right);
}

Node* minimalBST(int *arr, int start, int end) {
    if (start < 0 || start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node;
    root->data = arr[mid];
    root->left = minimalBST(arr, start, mid - 1);
    root->right = minimalBST(arr, mid + 1, end);
    return root;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = minimalBST(arr, 0, n-1);
    
    cout << "Inorder traversal\n";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal\n";
    postorder(root);
    cout << endl;
    return 0;
}