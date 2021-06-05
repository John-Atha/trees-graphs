#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
    public:
    stack<int> my_stack;
    vector<int> seen;
    void DFS(int curr, vector<int> adj[]) {
        //cout << "DFS from " << curr << endl;
        for (int v : adj[curr]) {
            //cout << "I see node " << v << ":" << endl;
            if (!seen[v]) {
                //cout << "Not seen" << endl;
                seen[v] = true;
                DFS(v, adj);
            }
            else {
                //cout << "Already seen" << endl;
            }
        }
        my_stack.push(curr);
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    seen.clear();   
	    for (int i=0; i<V; i++) {
            seen.push_back(false);
        }
        seen[0] = true;
        DFS(0, adj);
        for (int v=0; v<V; v++) {
            if (!seen[v]) {
                seen[v] = true;
                DFS(v, adj);
            }
        }
        vector<int> answer;
        while (!my_stack.empty()) {
            answer.push_back(my_stack.top());
            //cout << my_stack.top() << " - ";
            my_stack.pop();
        }
        //cout << endl;
        return answer;
	}
};
