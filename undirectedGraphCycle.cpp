#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public:
        vector<int> seen;
        vector<int> parent;
        bool detected = false;
    
    void Init(int n) {
        seen.clear();
        parent.clear();
        for (int i=0; i<n; i++) {
            seen.push_back(false);
            parent.push_back(-1);
        }
    }
    
    void DFS(int curr, int par, vector<int> adj[]) {
        //cout << "DFS from " << curr << endl;
        if (detected) {
            return;
        }
        if (seen[curr]) {
            detected = true;
            return;
        }
        else {
            seen[curr] = true;
            parent[curr] = par;
            for (int v : adj[curr]) {
                if (v!=parent[curr]) {
                    DFS(v, curr, adj);
                }
            }
        }
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int> adj[])
	{
	    Init(V);
	    for (int i=0; i<V; i++) {
	        if (!seen[i] && !detected) {
	            DFS(i, -1, adj);
	        }
	    }
	    return detected;
	}
};
