#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
	private:
    stack<int> S;
    vector<bool> visited;

    void DFS(int v, vector<int> adj[]) {
        if (visited[v]) return;
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) DFS(u, adj);
        }
        S.push(v);
    }

    void init(int V) {
        while (!S.empty()) S.pop();
        visited.clear();
        for (int i=0; i<V; i++) {
            visited.push_back(false);
        }
    }

    void stackFill(int V, vector<int> adj[]) {
        init(V);
        for (int i=0; i<V; i++) {
            if (!visited[i]) DFS(i, adj);
        }
    }

    void buildTranspose(int V, vector<int> adj[], vector<int> trans[]) {
        for (int v=0; v<V; v++) {
            for (int u : adj[v]) {
                trans[u].push_back(v);
            }
        }
    }

    int countConnected(int V, vector<int> trans[]) {
        int count = 0;
        for (int i=0; i<V; i++) {
            visited[i] = false;
        }
        while (!S.empty()) {
            int v = S.top();
            S.pop();
            if (!visited[v]) {
                count++;
                DFS(v, trans);
                bool all_visited = true;
                for (int i=0; i<V; i++) {
                    if (!visited[i]) {
                        all_visited = false;
                        break;
                    }
                }
                if (all_visited) break;
            }
        }
        return count;
    }

    public:
	//Function to find number of strongly connected components in the graph.

    int kosaraju(int V, vector<int> adj[]) {
        stackFill(V, adj);
        vector<int> trans[V];
        buildTranspose(V, adj, trans);
        return countConnected(V, trans);
    }
};