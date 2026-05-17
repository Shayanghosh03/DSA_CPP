#include<iostream>
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
  private:
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right) + 1;
    }

  public:
    bool isBalanced(Node* root) {
        if(root == NULL) {
            return true;  
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        return (left && right && diff); 
    }
};