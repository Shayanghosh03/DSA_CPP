#include<iostream>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode* temp = root;
    int pre = -1;
    int scc = -1;

    while(temp != NULL && temp -> data != key) {
        if(temp -> data > key) {
            scc = temp -> data;
            temp = temp -> left;
        } else {
            pre = temp -> data;
            temp = temp -> right;
        }
    }
    TreeNode* leftTree = temp -> left;
    while(leftTree != NULL) {
        pre = leftTree -> data;
        leftTree = leftTree -> right;
    }
    TreeNode* rightTree = temp -> right;
    while(rightTree != NULL) {
        scc = rightTree -> data;
        rightTree = rightTree -> left;
    }

    pair<int, int> ans = make_pair(pre, scc);

    return ans;
}