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
public:
    pair<int, int> diameterFast(Node* root) {
        if(root == NULL) {
            return {0, 0};
        }

        auto left = diameterFast(root->left);
        auto right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        int diameter = max(op1, max(op2, op3));
        int height = max(left.second, right.second) + 1;

        return {diameter, height};
    }

    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};