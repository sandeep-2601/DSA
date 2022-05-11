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
void topview(Node* root,int idx) {
    if(root == NULL) return;
    if(mp.find(idx) == mp.end()) {
        mp[idx] = root->val;
    }  
    topview(root->left,idx-1);
    topview(root->right,idx+1);
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

    topview(root,0);

    for(auto i: mp) 
        cout<<i.second<<" ";

    return 0;    
}