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

vector<int> traversal;

void findLeftBoundary(Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    traversal.push_back(root->val);
    if(root->left != NULL)
        findLeftBoundary(root->left);
    else 
        findLeftBoundary(root->left);
}

void leafNodes(Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        traversal.push_back(root->val);
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

void findRightBoundary(Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->right != NULL)
        findRightBoundary(root->right);
    else
        findRightBoundary(root->left);
    traversal.push_back(root->val);
}

void boundaryTraversal(Node *root) {
    if(root == NULL) return;

    findLeftBoundary(root);

    leafNodes(root);

    findRightBoundary(root->right);
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

    boundaryTraversal(root);

    for(int i: traversal)
        cout<<i<<" ";

    return 0;
    
}