#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution {
  private:
    Node* solve(Node* root, int& k, int node) {
        if(root == NULL) {
            return NULL;
        }
        if(root -> data == node) {
            return root;
        }
        
        Node* leftAns = solve(root -> left, k, node);
        Node* rightAns = solve(root -> right, k, node);
        
        if(leftAns != NULL || rightAns != NULL) {
            k--;
            if(k == 0) {
                return root;
            }
            return (leftAns != NULL) ? leftAns : rightAns;
        }
        return NULL;
    }
  public:
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node* ans = solve(root, k, node);
        
        if(ans == NULL || ans -> data == node) {
            return -1;
        } else {
            return ans -> data;
        }
    }
};
