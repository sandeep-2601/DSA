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

   
map<int,int> mp;
void rightView(Node *root,int level) {
    if(root == NULL) return;
    mp[level] = root->val;
    rightView(root->left,level+1);
    rightView(root->right,level+1);
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

    rightView(root,0);

    vector<int> res;

    for(auto it: mp)
        res.push_back(it.second);

    for(int i : res)
        cout<<i<<" ";   

    return 0; 
}