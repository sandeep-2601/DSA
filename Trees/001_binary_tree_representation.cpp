#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
    Node(int val,Node* left,Node* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int main() {

    Node* root = new Node(4);
    Node *left1 = new Node(5);
    Node *right1 = new Node(6);

    root->left =  left1;   //assigning left child of root node
    root->right = right1;  //assigning right child of root node

    cout<<root->val;       //4
    cout<<root->left->val; //5
    cout<<root->right->val; //6

    return 0;
}