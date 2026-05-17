#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int left = height(root -> left);
        int right = height(root -> right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    int diameter(Node* root) {
        // Base Case
        if(root == NULL) {
            return 0;
        }
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root -> left) + height(root -> right);
        
        int ans = max(op1, max(op2, op3));
        
        return ans;
    }
};