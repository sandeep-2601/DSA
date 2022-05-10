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

int isBalanced(Node *root) {
    if(root == NULL) return 0;
    int left  = isBalanced(root->left);
    int right = isBalanced(root->right);
    if(left == -1 || right == -1) return -1;
    if(abs(left-right) > 1) return -1;
    return 1 + max(left,right);
}

int main() {

    Node* root   = new Node(1);
    Node* left   = new Node(2);
    Node* right  = new Node(3);
    Node* left1  = new Node(4);
    Node* right1 = new Node(5);
    Node* left2  = new Node(6);
    Node* right2 = new Node(7);
    
    root->left   = left;  
    root->right  = right;  
    left->left   = left1;
    left->right  = right1;
    right->left  = left2;
    right->right = right2; 

    cout<<isBalanced(root);

    isBalanced(root)!=-1?cout<<"balanced":cout<<"notbalanced";
    
}