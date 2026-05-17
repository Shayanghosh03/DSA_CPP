#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        map<int, int> bottomNode;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            bottomNode[hd] = frontNode -> data;
            
            if(frontNode -> left) {
                q.push(make_pair(frontNode -> left, hd - 1));
            }
            if(frontNode -> right) {
                q.push(make_pair(frontNode -> right, hd + 1));
            }
        }
        for(auto i : bottomNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};