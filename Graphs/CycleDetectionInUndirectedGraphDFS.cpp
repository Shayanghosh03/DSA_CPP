#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
using namespace std;
// USE DFS

bool isCycleDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {

    visited[node] = true;
    for(auto neighbour : adj[node]) {
        // If not visited, do DFS
        if(!visited[neighbour]) {

            bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);

            if(cycleDetected) {
                return true;
            }
        }
        // If visited and not parent => cycle
        else if(neighbour != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Create Adjacency List
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < m; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Handle disconnected components
    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool ans = isCycleDFS(i, -1, visited, adj);
            if(ans) {
                return "Yes";
            }
        }
    }
    return "No";
}