#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int, int>> adj[vertices];
    for(int i=0;i<vec.size();i++) {
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]) {
            int curr = it.first;
            int currDis = it.second;
            if(dist[curr] > dist[node] + currDis) {
                dist[curr] = dist[node] + currDis;
                pq.push({dist[curr], curr});
            }
        }
    }
    
    return dist;
    
}
