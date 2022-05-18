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

void childrenSum(Node *root) {
    if(root == NULL) return;
    int child = 0;
    if(root->left)
        child += root->left->val;
    if(root->right)
        child += root->right->val;

    if(child >= root->val) {
        root->val = child;
    }
    else {
        if(root->left)
            root->left->val = root->val;
        if(root->right)
            root->right->val = root->val;
    }

    childrenSum(root->left);
    childrenSum(root->right);
    int rootval = 0;
    if(root->left) rootval += root->left->val;
    if(root->right) rootval += root->right->val;

    if(root->left != NULL || root->right != NULL)
        root->val = rootval;
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


    childrenSum(root);
    
    cout<<root->val;

    return 0;
}