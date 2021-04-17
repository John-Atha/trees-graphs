class Solution:
    def __init__(self):
        self.seen = []
        self.answer = []

    def DFS(self, adj, curr):
        if not self.seen[curr]:
            self.answer.append(curr)
            self.seen[curr]=True
            for i in adj[curr]:
                self.DFS(adj, i)
    
    def dfsOfGraph(self, V, adj):
        self.seen = [False for i in range(V)]
        curr = 0
        self.answer = []
        self.DFS(adj, curr)
        return self.answer