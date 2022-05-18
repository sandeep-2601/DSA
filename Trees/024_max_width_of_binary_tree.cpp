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

 int widthOfBinaryTree(Node* root) {
        
        queue<pair<Node*,long>> q;
        q.push({root,0});
        long ans = INT_MIN;
        
        while(!q.empty()) {
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans,end-start+1);
            int n = q.size();
            
            
            for(int i=0;i<n;i++) {
                
                Node* tempNode = q.front().first;
                long idx = q.front().second - start;
                q.pop();
                if(tempNode->left) q.push({tempNode->left,idx*2+1});
                if(tempNode->right)q.push({tempNode->right,idx*2+2});
            }
        }
        
        
        return ans;
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

    cout<<widthOfBinaryTree(root);
    
}