#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {

    vector<int> ans;
    vector<bool> visited(n, false);
    queue<int> q;
    // Start BFS from node 0
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // Traverse all neighbours
        for(auto neighbour : adj[frontNode]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return ans;
}