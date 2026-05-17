#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void leftTraversal(Node* root, vector<int>& ans) {
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
            return;
        }
        ans.push_back(root -> data);
        if(root -> left) {
            leftTraversal(root -> left, ans);
        } else {
            leftTraversal(root -> right, ans);
        }
    }
    void traverseLeaf(Node* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back(root -> data);
            return;
        }
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
    }
    void rightTraversal(Node* root, vector<int>& ans) {
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
            return;
        }
        if(root -> right) {
            rightTraversal(root -> right, ans);
        } else {
            rightTraversal(root -> left, ans);
        }
        ans.push_back(root -> data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        ans.push_back(root -> data);
        
        leftTraversal(root -> left, ans);
        
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
        
        rightTraversal(root -> right, ans);
        
        return ans;
    }
};