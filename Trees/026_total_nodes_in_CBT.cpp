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

int lheight(TreeNode *root) {
        if(root == NULL) return 0;
        return 1 + lheight(root->left);
    }

int rheight(TreeNode *root) {
    if(root == NULL) return 0;
    return 1 + rheight(root->right);
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    
    int left  = lheight(root);
    int right = rheight(root);
    
    if(left == right) return pow(2,left)-1;
    return 1 + countNodes(root->left) + countNodes(root->right);
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

    cout<<countNodes(root);
    
}