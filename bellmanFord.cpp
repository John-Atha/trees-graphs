#include <iostream>
using namespace std;
#include <vector>
#include <limits>

class Solution {

private:
    vector<int> dist;
    void distInit(int n) {
        dist.clear();
        for (int i=0; i<n; i++) {
            int inf = numeric_limits<int>::max();
            dist.push_back(inf);
        }
        dist[0] = 0;
    }
    void calc(vector<vector<int>> edges) {
        for (int u=0; u<int(edges.size()); u++) {
            for (int v=0; v<int(edges[u].size()); v++) {
                if (dist[v]>dist[u]+edges[u][v]) {
                    dist[v] = dist[u] + edges[u][v];
                }
            }
        }
    }
    bool checkNegative(vector<vector<int>> edges) {
        for (int u=0; u<int(edges.size()); u++) {
            for (int v=0; v<int(edges[u].size()); v++) {
                if (dist[v]>dist[u]+edges[u][v]) {
                    return true;
                }
            }
        }
        return false;
    }

public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
        distInit(n);
        for (int i=0; i<n-1; i++) {
            calc(edges);
        }
        return checkNegative(edges);
	}
};
