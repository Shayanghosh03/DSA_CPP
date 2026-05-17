#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    vector<vector<int>> verticalOrder(Node *root) {
        
        map<int, map<int, vector<int>>> node;
        queue<pair<Node*, pair<int, int>>> q;

        if(root == NULL) {
            return {};
        }

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            node[hd][lvl].push_back(frontNode->data);

            if(frontNode->left) {
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            }

            if(frontNode->right) {
                q.push({frontNode->right, {hd + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto i : node) {
            vector<int> col;
            for(auto j : i.second) {
                for(auto k : j.second) {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};