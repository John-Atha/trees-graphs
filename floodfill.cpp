/* runs fine locally, 
   but gets SIGABRT on geeksforgeeks
*/

#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <tuple>

int T, M, N;
vector<vector<tuple<int, int>>> arr;
queue<tuple<int, int, int>> q;

void printArr() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << "(" << get<0>(arr[i][j]) << ", " <<  get<1>(arr[i][j]) << ")"<< endl;
        }
    }
}

void printQueue() {
    queue<tuple<int, int, int>> q2;
    while (!q.empty()) {
        tuple<int, int, int> x = q.front();
        q.pop();
        cout << "(" << get<0>(x) << ", " <<  get<1>(x) << ", " <<  get<2>(x) << ")"<< endl;
        q2.push(x);
    }
    while (!q2.empty()) {
        tuple<int, int, int> x = q2.front();
        q2.pop();
        q.push(x);
    }
}

int findMax() {
    //printArr();
    int max = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            max = get<1>(arr[i][j])>max ? get<1>(arr[i][j]) : max;
        }
    }
    return max;
}

void floodfill() {
    //printArr();
    //cout << "I am floodfill" << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            //cout << "i= " << i << endl;
            //cout << "j= " << j << endl;
            if (get<0>(arr[i][j])==0) {
                q.push(tuple<int, int, int>{i, j, 0});
            }
        }
    }
    //cout << "I initialize the queue as:" << endl;
    //printQueue();
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();
        int x = get<0>(curr);
        int y = get<1>(curr);
        int time = get<2>(curr);
        //cout << "I dequeue the (" << x << ", " << y << ", " << time << ")" << endl;
        if ( (get<0>(arr[x][y])==0 && get<1>(arr[x][y])>time) || get<0>(arr[x][y])==1 || get<1>(arr[x][y])==0 ) {
            //cout << "useful" << endl;
            get<0>(arr[x][y])=0;
            get<1>(arr[x][y])=time;
            if (x-1>0) {
                q.push(tuple<int, int, int>{x-1, y, time+1});
            }
            if (x+1<N) {
                q.push(tuple<int, int, int>{x+1, y, time+1});
            }
            if (y-1<0) {
                q.push(tuple<int, int, int>{x, y-1, time+1});
            }
            if (y+1<M) {
                q.push(tuple<int, int, int>{x, y+1, time+1});
            }
        }
        else {
            //cout << "not useful" << endl;
        }
    }
}

void solveOne() {
    cin >> N;
    cin >> M;
    arr.clear();
    while (!q.empty()) {
        q.pop();
    }
    for (int i=0; i<N; i++) {
        vector<tuple<int, int>> line;
        for (int j=0; j<M; j++) {
            int x;
            cin >> x;
            line.push_back(tuple<int, int>{x, 0});
        }
        arr.push_back(line);
    }
    floodfill();
    cout << findMax() << endl;
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        solveOne();
    }

}