#include <bits/stdc++.h>
using namespace std;

class Solution {

    private:
    vector<int> disc;
    vector<int> low;
    vector<bool> onStack;
    stack<int> S;
    int time;
    vector<vector<int>> answer;
    
    void init(int V) {
        time = 0;
        while (!S.empty()) S.pop();
        disc.clear();
        low.clear();
        onStack.clear();
        answer.clear();
        for (int i=0; i<V; i++) {
            disc.push_back(-1);
            low.push_back(-1);
            onStack.push_back(false);
        }
    }

    /* sort lexicographically the SCCs */
    void sortAnswer() {
        auto compare = [](vector<int> a, vector<int> b) {
            return (a[0]<b[0]);
        };
        sort(answer.begin(), answer.end(), compare);
    }
    
    /* recursive function that computes the SCCs */
    void strong(int v, vector<int> adj[]) {
        disc[v] = time;
        low[v] = time;
        time++;
        S.push(v);
        onStack[v] = true;
        // compute disc[v], low[v]
        for (int w : adj[v]) {
            // if w not visited yet through DFS, iterate through it
            if (disc[w] == -1) {
                strong(w, adj);
                low[v] = low[v]<low[w] ? low[v] : low[w];                
            }
            // w has been visited through DFS and belongs to the same SCC
            else if (onStack[w]) {
                low[v] = low[v]<disc[w] ? low[v] : disc[w];
            }
        }
        // if v is a root node for its SCC
        if (disc[v] == low[v]) {
            vector<int> SCC;
            while (!S.empty()) {
                int w = S.top();
                S.pop();
                onStack[w] = false;
                SCC.push_back(w);
                if (w == v) break;
            }
            sort(SCC.begin(), SCC.end());
            answer.push_back(SCC);
        }
    }


	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        init(V);
        for (int v=0; v<V; v++) {
            if (disc[v] == -1) strong(v, adj);
        }
        sortAnswer();
        return answer;
    }
};






