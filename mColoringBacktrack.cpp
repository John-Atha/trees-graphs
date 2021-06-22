#include <bits/stdc++.h>
using namespace std;

#include <vector>

/* global variables */
vector<int> colors;

void printVec(vector<int> vec) {
    for (int i : vec) {
        cout << i << ", ";
    }
    cout << endl;
}

void init(int V) {
    colors.clear();
    for (int i=0; i<V; i++) {
        colors.push_back(0);
    }
}

bool isSafe(bool graph[101][101], int curr, int V, int tempColor) {
    for (int i=0; i<V; i++) {
        if (graph[curr][i]) {
            if (colors[i] == tempColor) return false;
        }
    } 
    return true;
}


bool solve(bool graph[101][101], int curr, int V, int m) {
    cout << "-- N = " << V << ", I am solve for " << curr << ":" << endl;
    cout << "With colors: ";
    printVec(colors); 
    if (curr == V) {
        cout << "----------------curr==V-----------------" << endl;
        return true;
    }
    for (int i=1; i<=m; i++) {
        cout << "Trying color " << i << ":" << endl;
        if (isSafe(graph, curr, V, i)) {
            colors[curr] = i;
            cout << "It is safe" << endl;
            if (solve(graph, curr+1, V, m)) {
                cout << "-----end------" << endl;
                return true;
            }
            else {
                colors[curr] = 0;
            }
        }
        else {
            cout << "Not safe" << endl;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V) {
    init(V);
    return solve(graph, 0, V, m);
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i=0; i<n; i++) {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
}