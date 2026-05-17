#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};
// Using Recursion
bool searchInBST1(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL) {
        return false;
    }

    if(root -> data == x) {
        return true;
    }
    if(root -> data > x) {
        return searchInBST1(root -> left, x);
    } else {
        return searchInBST1(root -> right, x);
    }
}
//Using Loop
bool searchInBST2(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int>* temp = root;

    while(temp != NULL) {
        if(temp -> data == x) {
            return true;
        }
        if(temp -> data < x) {
            temp = temp -> right;
        } else {
            temp = temp -> left;
        }
    } 
    return false;
}