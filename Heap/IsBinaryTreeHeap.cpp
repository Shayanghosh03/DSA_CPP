#include<iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    int countNode(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = 1 + countNode(root -> left) + countNode(root -> right);
        return ans;
    }
    bool isCBT(Node* root, int index, int cnt) {
        if(root == NULL) {
            return true;
        }
        
        if(index >= cnt) {
            return false;
        } else {
            bool left = isCBT(root -> left, 2*index+1, cnt);
            bool right = isCBT(root -> right, 2*index+2, cnt);
            
            return (left && right);
        }
    }
    bool ismaxOrder(Node* root) {
        if(root -> left == NULL && root -> right == NULL) {
            return true;
        }
        if(root -> right == NULL) {
            return (root -> data > root -> left -> data);
        } else {
            bool left = ismaxOrder(root -> left);
            bool right = ismaxOrder(root -> right);
            
            if(left && right && (root -> data > root -> left -> data && root -> data > root -> right -> data)) {
                return true;
            }
            return false;
        }
    }
  public:
    bool isHeap(Node* tree) {
        // code here
        int index = 0;
        int totalCount = countNode(tree);
        
        if(isCBT(tree, index, totalCount) && ismaxOrder(tree)) {
            return true;
        } else {
            return false;
        }
    }
};