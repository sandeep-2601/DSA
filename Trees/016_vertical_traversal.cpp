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

vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;

        while(!q.empty()) {
            auto node = q.front();
            int v = node.second.first;
            int level = node.second.second;
            mp[v][level].insert(node.first->val);
            q.pop();
            if(node.first->left != NULL)
                q.push({node.first->left,{v-1,level+1}});
            if(node.first->right != NULL)
                q.push({node.first->right,{v+1,level+1}});
        }

         for(auto it1:mp) {
            vector<int> temp;
            for(auto it2:it1.second) {
                for(auto it3:it2.second) {
                    temp.push_back(it3);
                }
            }
            res.push_back(temp);
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

    inorder(root);
    
}
