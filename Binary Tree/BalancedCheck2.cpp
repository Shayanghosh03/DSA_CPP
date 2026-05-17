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
    pair<bool, int> isBalancedFast(Node* root) {
        if(root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<int, int> left = isBalancedFast(root -> left);
        pair<int, int> right = isBalancedFast(root -> right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        if(leftAns && rightAns && diff) {
            ans.first = true;
        } else {
            ans.first = false;
        }
        return ans;
    }
  public:
    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
    }
};