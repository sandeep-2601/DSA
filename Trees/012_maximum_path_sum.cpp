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

int maxval = INT_MIN;
int pathsum(Node *root) {
    if(root == NULL) return 0;
    int left = max(0,pathsum(root->left));
    int right = max(0,pathsum(root->right));
    maxval = max(maxval,root->val + left+right);
    
    return root->val + max(left,right);
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

    pathsum(root);

    cout<<maxval;
    
}