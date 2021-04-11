// Dfs to compute the max distance d(X, v) from given node X in a tree 

#include <iostream>
using namespace std;
#include <vector>
#include <set>
vector<vector<int>> tree;
vector<int> d;
int N, X;
vector<bool> seen;

int findMax(vector<int> d) {
    int maxD = 0;
    for (int i=0; i<int(d.size()); i++) {
        maxD = d[i]>maxD ? d[i] : maxD;
    }
    return maxD;
}

void printTree() {
    cout << "Tree:" << endl;
    for (int i=0; i<int(tree.size()); i++) {
        cout << i << ": ";
        for (int j=0; j<int(tree[i].size()); j++) {
            cout << tree[i][j] << ", ";
        }
        cout << endl;
    }
}

void addEdge(int a, int b) {
    //cout << "I put edge " << a << "-" << b << endl;
    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
}

/* fills N, K, tree vector and clears seen set */
void initialize() {
    d.clear();
    tree.clear();
    seen.clear();
    cin >> N;
    //cout << "N: " << N << endl;
    cin >> X;
    //cout << "X: " << X << endl;
    X--;
    for (int i=0; i<N; i++) {
        vector<int> line;
        tree.push_back(line);
        d.push_back(0);
        seen.push_back(false);
    }
    //printTree();
    for (int i=0; i<N-1; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        addEdge(u, v);
        //printTree();
    }
}

void DFS(int x) {
    //cout << "DFS from " << x << ":" << endl;
    for (int v : tree[x]) {
        //cout << "I am node " << v << endl;
        // if v is not seen
        if (!seen[v]) {
            //cout << "I am new, i have distance " << d[x]+1 << endl;
            seen[v]=true;
            d[v]=d[x]+1;
            //cout << "Max distance is: " << maxD << endl;
            DFS(v);
        }
        else {
            //cout << "I am visited already" << endl;
        }
    }
}

/* will perform the DFS from X and compute the max distance */
void compute() {
    seen[X]=true;
    DFS(X);
    cout << findMax(d) << endl;
}

void solve() {
    initialize();
    compute();
}

int main() {
    int T;
    cin >> T;
    //cout <<"T: " << T << endl;
    for (int i=0; i<T; i++) {
        //cout << "test case "<< i << ":" << endl;
        solve();
    }
}