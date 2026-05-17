#include<iostream>
using namespace std;
// Tree node

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> isSumTreeFast(Node* root) {
        if(root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if(root -> left == NULL && root -> right == NULL) {
            pair<bool, int> p = make_pair(true, root -> data);
            return p;
        }
        
        pair<bool, int> leftAns = isSumTreeFast(root -> left);
        pair<bool, int> rightAns = isSumTreeFast(root -> right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        bool cond = root -> data == leftAns.second + rightAns.second;
        
        pair<bool, int> ans;
        
        if(left && right && cond) {
            ans.first = true;
            ans.second = root -> data + leftAns.second + rightAns.second;
        } else {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreeFast(root).first;
    }
};