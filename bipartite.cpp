#include <iostream>
using namespace std;

#include <vector>

void printVec(vector<int> vec) {
    for (int i : vec) {
        cout << i << ", ";
    }
    cout << endl;
}
void printGraph(vector<int> graph[], int V) {
    cout << "graph:" << endl;
    for (int i=0; i<V; i++) {
        cout << i <<": ";
        printVec(graph[i]);
    }
}

class Solution {
    public:
    vector<int> visited;
    vector<int> colors;
    int V;
    bool isBipart = true;

    void init(int V) {
        this->visited.clear();
        this->colors.clear();
        this->V = V;
        this->isBipart = true;
        for (int i=0; i<V; i++) {
            this->visited.push_back(false);
            this->colors.push_back(-1);
        }
    }

    void DFS(int u, int par, vector<int> adj[], int isRoot = false) {
        if (!isBipart) return;
        ////cout << "Visited vector: ";
        //printVec(this->visited);
        //cout << "colors: ";
        //printVec(this->colors);
        //cout << "--->DFS from " << u << " with parent " << par << endl;
        //if (isRoot) //cout << "It is root" << endl;
        //else //cout <<"It is not root" << endl;

        // mark as visited
        this->visited[u] = true;
        // paint opposite from parent
        if (isRoot) this->colors[u] = 0;
        else {
            this->colors[u] = this->colors[par]==0 ? 1 : 0;
        }
        //cout << "I am painting it color: " << this->colors[u] << endl;
        //cout << "I have neighbours: ";
        //printVec(adj[u]);
        for (int v : adj[u]) {
            //cout << "I am seeing neighbour " << v << ": ";
            if (this->visited[v] && this->colors[v]==this->colors[u]) {
                //cout << "Visited with same color, RETURNING FALSE" << endl;
                this->isBipart = false;
            }
            else if (!this->visited[v]) {
                //cout << "Not visited, starting DFS from here..." << endl;
                this->DFS(v, u, adj, false);
            }
            else {
                //cout << "Visited with the other color, moving on..." << endl;
            }
        }
    }

    bool isBipartite(int V, vector<int> adj[]) {
        this->init(V);
        //printGraph(adj, V);
        for (int i=0; i<V; i++) {
            if (!this->visited[i] && this->isBipart) {
                //this->visited[i] = true;
                this->DFS(i, -1, adj, true);
            }
        }
        return this->isBipart;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans) cout << "1" << endl;
        else cout << "0" << endl;
    }
}