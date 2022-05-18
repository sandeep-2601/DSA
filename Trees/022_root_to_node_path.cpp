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
bool found = false;
vector<int> res;
void rootToNode(Node * root,int target) {
if(root == NULL) return;
if(root->val == target) {
    res.push_back(root->val);
    found = true;
    return;
}
rootToNode(root->left,target);
if(!found)
rootToNode(root->right,target);
if(found)
res.push_back(root->val);
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

    rootToNode(root,7);
    
    for(int i=res.size()-1;i>=0;i--)
        cout<<res[i]<<" ";

    return 0;
}