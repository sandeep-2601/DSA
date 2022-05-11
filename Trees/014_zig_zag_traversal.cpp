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

vector<vector<int>> res;
        
vector<vector<int>> zigzagLevelOrder(Node* root) {
        if(root == NULL) return res;
        
        queue<Node*> q;
        q.push(root);
        
        vector<int> level;
        Node *temp; 
        bool flag = true;
        
        while(!q.empty()) {
        
            int n = q.size();
            vector<int> level(n);
            
            for(int i=0;i<n;i++) {
                
                temp = q.front();
                q.pop();
                
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
                
                int idx = flag?i:n-i-1;
                level[idx] = temp->val;
            }
            
            res.push_back(level);
                
            flag = !flag;
        }
        
        return res;
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

    zigzagLevelOrder(root);

    for(auto it1 : res) {
        for(int it:it1){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}