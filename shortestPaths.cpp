#include <bits/stdc++.h>
using namespace std;

int N = 9;
vector<int> dist(N, INT_MAX);
void bfs(vector<int> adj[], int N, int src) {
    
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for(auto it : adj[curr]) {
            if(dist[it] > dist[curr] + 1) {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }
    
    
}

int main() {
    vector<int> adj[N];
    adj[0] = {1,3};
    adj[1] = {0,2,3};
    adj[2] = {1,6};
    adj[3] = {0,4};
    adj[4] = {3,5};
    adj[5] = {4,6};
    adj[6] = {2, 5, 7, 8};
    adj[7] = {6, 8};
    adj[8] = {6, 7};
    
    bfs(adj, N, 0);
    
    for(int i=0;i<N;i++) {
        cout << dist[i] << " ";
    }
	
}
