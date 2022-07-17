#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, int n, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &visited) {
    visited[node] = 1;
    
    for(auto it : adj[node]) {
        if(!visited[it.first]) {
            topoSort(it.first, n, adj, st, visited);
        }
    }
    st.push(node);
}

void shortestPath(int src, int n, vector<pair<int,int>> adj[]) {
    
    vector<int> visited(n, 0);
    stack<int> st;
    vector<int> dist(n, INT_MAX);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            topoSort(i, n, adj, st, visited);
        }
    }
    
    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(dist[node] != INT_MAX) {
            for(auto it : adj[node]) {
                if(dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        cout << dist[i] << " " ;
    }
    
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	for(int i=0;i<m;i++) {
	    int a, b, wt;
	    cin >> a >> b >> wt ;
	    adj[a].push_back({b, wt});
	}
	
	shortestPath(0, n, adj);
	return 0;
}
