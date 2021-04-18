import math
class Solution:
    # Function to construct and return cost of MST for a graph
    # represented using adjacency matrix representation
    '''
    V: nodes in graph
    adj: adjacency list for the graph
    S: Source
    '''
    def __init__(self):
        self.seen = set()
        self.d = []

    def dijkstra(self, V, adj, S):
        self.d = [math.inf for i in range(V)]
        self.d[S] = 0
        # while not all vertices in seen
        while len(self.seen)!= V:
            # find the not-seen with the minimum d
            minD = math.inf
            minNode = 0
            for node in range(V):
                if node not in self.seen and self.d[node]<minD:
                    minD = self.d[node]
                    minNode = node
            # add it in the seen-set
            self.seen.add(minNode)
            # update distances of all adjacent
            for nodeL in adj[minNode]:
                node = nodeL[0]
                w = nodeL[1]
                self.d[node] = min(self.d[node], self.d[minNode]+w)
        return self.d
