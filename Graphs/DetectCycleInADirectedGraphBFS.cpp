// Using Kahn's Algorithm (BFS)
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // Create Adjacent List
  unordered_map<int, list<int>> adj;
  for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // Find all indegress
  vector<int> indegree(n + 1);
  for(auto i : adj) {
    for(auto j : i.second) {
      indegree[j]++;
    }
  }

  // Push in the queue which is 0 indegree nodes
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  // Do BFS
  int cnt = 0;
  while(!q.empty()) {
    int front = q.front();
    q.pop();

    // Inc count
    cnt++;

    // Neighbour indegree update
    for(auto neighbour : adj[front]) {
      indegree[neighbour]--;
      if(indegree[neighbour] == 0) {
        q.push(neighbour);
      }
    }

  }

  if(cnt == n) {
    return false;
  } else {
    return true;
  }

}