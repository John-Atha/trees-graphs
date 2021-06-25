#include <bits/stdc++.h>
using namespace std;

class Solution { 
    private:
    vector<int> visited;
    vector<int> degree;    
    
    void DFS(int u, vector<int> adj[]) {
        degree[u] = int(adj[u].size());
        if (visited[u]) return;
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) DFS(v, adj);
        }
    }

    void init(int V) {
        visited.clear();
        degree.clear();
        for (int i=0; i<V; i++) {
            visited.push_back(false);
            degree.push_back(0);
        }
    }

    public:
    int isEularCircuit(int V, vector<int>adj[]) {
        init(V);
        // make a DFS and test that all vertices (with degree > 0) are connected
        DFS(0, adj);
        for (int v=0; v<V; v++) {
            if (visited[v]) continue;
            // if not visited with degree > 0, neither path nor cycle exist
            if (int(adj[v].size())>0) return 0;
        }
        int odds = 0;
        for (int v=0; v<V; v++) {
            if (degree[v]%2==1) {
                if (odds > 2) return 0;
                odds++;
            }
        }
        if (odds == 0) return 2;
        else if (odds == 2) return 1;
    }
};