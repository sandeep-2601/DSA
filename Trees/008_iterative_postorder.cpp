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

void iterativePostorder(Node* root) {
    if(root == NULL) return; 
    stack<Node*> st1;
    stack<Node*> st2;
    Node* temp;

    st1.push(root);

    while(!st1.empty()) {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left != NULL)
            st1.push(temp->left);
        if(temp->right != NULL)
            st1.push(temp->right);
    }


    while(!st2.empty()) {
        cout<<st2.top()->val<<" ";
        st2.pop();
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

    iterativePostorder(root);
    
}