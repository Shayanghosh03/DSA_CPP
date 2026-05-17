#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>
#include<climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create adjacency list
    unordered_map<int, list<pair<int, int>> > adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);
    for(int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()) {
        // Fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove top node
        st.erase(st.begin());

        // Traverse on neighbour
        for(auto neighbour : adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // If record Found then erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                // Distance Update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // Record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
