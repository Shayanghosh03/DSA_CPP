#include<iostream>
#include<vector>
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
    void solve(Node* root, int& count, int k, vector<int> path) {
        if(root == NULL) {
            return;
        }
        path.push_back(root -> data);
        
        solve(root -> left, count, k, path);
        solve(root -> right, count, k, path);
        
        
        int sum = 0;
        for(int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }
        path.pop_back();
    }
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        vector<int> path;
        int count = 0;
        solve(root, count, k, path);
        
        return count;
    }
};