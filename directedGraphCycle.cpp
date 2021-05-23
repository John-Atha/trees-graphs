#include <iostream>
using namespace std;
#include <vector>


class Solution
{
    public:
        vector<int> seen;
        vector<int> explored;
        bool detected;
        
        void Init(int n) {
            detected = false;
            seen.clear();
            explored.clear();
            for (int i=0; i<n; i++) {
                seen.push_back(false);
                explored.push_back(false);
            }
        }

        void DFS(int curr, vector<int> adj[]) {
            if (detected) {
                return;
            }
            else {
                if (seen[curr]) {
                    if (!explored[curr]) {
                        detected = true;
                        //cout << "FOUND" << endl << endl;
                        return;
                    }
                    else{
                        return;
                    }
                }
                else {
                    seen[curr] = true;
                    for (int v : adj[curr]) {
                        DFS(v, adj);
                    }
                    explored[curr] = true;
                }
            }
        }

        /* Function to detect cycle in a directed graph. */
        
        bool isCyclic(int V, vector<int> adj[]) {
            Init(V);
            for (int i=0; i<V; i++) {
                if (!explored[i]) {
                    DFS(i, adj);
                }
            }
            return detected;
        }


};