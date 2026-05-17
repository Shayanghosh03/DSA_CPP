#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    void solve(Node* root, vector<int>& ans, int level) {
        if(root == NULL) {
            return;
        }
        if(level == ans.size()) {
            ans.push_back(root -> data);
        }
        solve(root -> right, ans, level + 1);
        solve(root -> left, ans, level + 1);
    }
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        solve(root, ans, 0);
        
        return ans;
    }
};