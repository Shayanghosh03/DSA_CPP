#include<iostream>
#include<vector>
using namespace std;

class BinaryTreeNode {
public :
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int data) {
        this -> left = NULL;
        this -> right = NULL;
        this -> data = data;
	}
};

void inorderStore(BinaryTreeNode* root, vector<int>& arr) {
	if(root == NULL) {
		return;
	}
	inorderStore(root -> left, arr);
	arr.push_back(root -> data);
	inorderStore(root -> right, arr);
}
void preorderReplace(BinaryTreeNode* root, vector<int>& arr, int& index) {
	if(root == NULL) {
		return;
	}
	root -> data = arr[index];
	index++;
	preorderReplace(root -> left, arr, index);
	preorderReplace(root -> right, arr, index);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	inorderStore(root, arr);

	int index = 0;
	preorderReplace(root, arr, index);

	return root;
}