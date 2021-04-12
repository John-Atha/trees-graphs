/*
 T test cases
 in each one, given a tree, 
   find the abs difference of the sums of the nodes values
   at odd and even level
*/

#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <queue>
#include <tuple>
vector<vector<int>> tree;
vector<bool> seen;
vector<bool> odd;
int N;

void printVec(vector<bool> vec) {
    for (int i=0; i<int(vec.size()); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
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
    tree[a].push_back(b);
    tree[b].push_back(a);
}

void treeInit() {
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        vector<int> line;
        line.push_back(x);
        tree.push_back(line);
    }
    //printTree();
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        addEdge(a-1, b-1);
    }
    //printTree();
}

void BFS() {
    queue<tuple<int, int>> q;
    q.push(tuple<int, int>{0,0});
    odd[0]=true;
    while (!q.empty()) {
        tuple<int, int> t = q.front();
        q.pop();
        int curr = get<0>(t);
        int par = get<1>(t);
        //cout << "Popped from queue: (" << curr << ", " << par <<")" << endl;
        if (!seen[curr]) {
            seen[curr] = true;
            if (par!=curr) {
                if (!odd[par]) {
                    odd[curr]=true;
                }
            }
            for (int i=1; i<int(tree[curr].size()); i++) {
                q.push(tuple<int, int>{tree[curr][i], curr});
            }
        }
    }    
}

void diffCompute() {
    int sum1 = 0;
    int sum2 = 0;
    for (int i=0; i<int(odd.size()); i++) {
        if (odd[i]) {
            sum1 += tree[i][0]; 
        }
        else {
            sum2 += tree[i][0];
        }
    }
    cout << (sum1>sum2 ? sum1-sum2 : sum2-sum1) << endl;;
}

void init() {
    cin >> N;
    //cout << "N: " << N << endl;
    tree.clear();
    seen.clear();
    odd.clear();
    for (int i=0; i<N; i++) {
        seen.push_back(false);
        odd.push_back(false);
    }
}

void solveOne() {
    init();
    treeInit();
    BFS();
    diffCompute();
}

int main() {
    int T;
    cin >> T;
    //cout <<"T: " << T << endl;
    for (int i=0 ; i<T; i++) {
        solveOne();
    }
}