#include <iostream>
using namespace std;
#include <vector>

class Solution {
  public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n = int(matrix[0].size());
        int dist[n][n];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = matrix[i][j]==-1 ? INT32_MAX : matrix[i][j];    
            }
        }
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if ( (dist[i][j] > dist[i][k] + dist[k][j]) && dist[i][k]!=INT32_MAX && dist[k][j]!=INT32_MAX) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        for (int i =0; i<n; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = dist[i][j]==INT32_MAX ? -1 : dist[i][j];
            }
        }
    }
};