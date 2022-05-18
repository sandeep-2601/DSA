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

bool isPalindrome(vector<int> &temp,int n) {
    for(int i=0;i<n/2;i++) {
        if(temp[i] != temp[n-i-1]) return false;
    }
    return true;
}

bool isSymmetric(Node* root) {
    queue<Node*> q;
    Node* temp;
    q.push(root);

    while(!q.empty()) {
        
        int n = q.size();
        vector<int> rev;
        for(int i=0;i<n;i++) {
            
            temp = q.front();
            q.pop();
            if(temp == NULL)
                rev.push_back(-101);
            else
                rev.push_back(temp->val);
            if(temp!=NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        if (!isPalindrome(rev,rev.size())) {
            return false;
        };
        
        rev.clear();
    }
    
    return true;
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

    isSymmetric(root);

    return 0; 
}