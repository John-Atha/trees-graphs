#include <iostream>
using namespace std;

#include <vector>
#include <set>

/* global */
vector<vector<int>> graph;
vector<int> par;
int N, M;

void printGraph() {
    //cout << "Graph:" << endl;
    for (int u=0; u<N; u++) {
        //cout << u << ": ";
        for (int v=0; v<int(graph[u].size()); v++) {
            //cout << graph[u][v] << ", ";
        }
        //cout << endl;
    }
}
void printParents() {
    //cout << "Parents:" << endl;
    for (int i=0; i<N; i++) {
        //cout << par[i] << " - ";
    }
    //cout << endl;
}
void addEdge(int u, int v) {
    //cout << "I add the edge " << u-1 << " - " << v-1 << endl;
    graph[u-1].push_back(v-1);
    graph[v-1].push_back(u-1);
}
void edgeUnion(int u, int v) {
    //cout << "I unite the " << u  << "(" << par[u] << ")" << " - " << v << "(" << par[v] << ")" << endl;
    if (u!=v /* && par[u]!=par[v] */) {
        if (par[u]<par[v]) par[u] = par[v];
        else par[v] = par[u];
    }
}
int edgeFind(int u) {
    //cout << "I am edge-find for " << u << endl;
    if (u!=par[u] && u!=par[par[u]]) {
        par[u] = edgeFind(par[u]);
    }
    return par[u];
}
void initGraph() {
    cin >> N;
    cin >> M;
    int u, v;
    for (int i=0; i<N; i++) {
        par.push_back(i);
        vector<int> line;
        //line.push_back(i);
        graph.push_back(line);
    }
    for (int i=0; i<M; i++) {
        cin >> u;
        cin >> v;
        addEdge(u, v);
    }
}
void initTest() {
    graph.clear();
    par.clear();
    initGraph();
}
void unions() {
    //cout << "-------I AM THE UNIONS FUNC---------" << endl;
    for (int u=0; u<N; u++) {
        for (int v=0; v<int(graph[u].size()); v++) {
            edgeUnion(u, graph[u][v]);
        }
    }
}
void countConnected() {
    //cout << "I am counting connected components:" << endl;
    set<int> parents;
    int ccs = 0;
    //cout << "Parents:" << endl;
    /*for (int u=0; u<N; u++) {
        if (par[u])
    }*/
    for (int u=0; u<N; u++) {
        int myPar = edgeFind(u);
        //cout << myPar << ", ";
        // if you find a new parent
        if (parents.find(myPar) == parents.end()) {
            //cout << endl << "Found new: " << myPar << endl;
            parents.insert(myPar);
            ccs++;
        }
    }
    //cout << endl;
    //cout << "DONE" << endl;
    //printParents();
    cout << ccs-1 << endl;
}
void oneTest() {
    initTest();
    //printGraph();
    unions();
    unions();
    countConnected();
}
int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        //cout << "test " << i+1 << ":" << endl;
        oneTest();
    }
}