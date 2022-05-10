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
// the concept of pre order is to print the root node first Root,Left,Right
//  push root
//  and while stack is not empty pop the root and push right and left s
//  we push right first because we want reverse order as it is stack
//  we
void iterativePreorder(Node* root) {
    if(root == NULL) return;

    stack<Node*> s;
    s.push(root);
    Node* temp;
    while(!s.empty()) {
        temp = s.top();
        cout<<temp->val;
        s.pop();
        if(temp->right != NULL)
            s.push(temp->right);
        if(temp->left != NULL)
            s.push(temp->left);
    }
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

    iterativePreorder(root);
    
}