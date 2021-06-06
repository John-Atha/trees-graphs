class Solution:
    inf = float('inf')

    # set with vertices included in the MST
    included = set()

    # list of w(edges) that provide the cheapest connection to each vertex 
    parent_edges = []

    # updates the weights of all neighbour vertices of the picked one
    def update(self, u, adj):
        #print(f"I picked vertex: {u}")
        for [v,w] in adj[u]:
            if v not in self.included and (self.parent_edges[v] > w or self.parent_edges[v]==-1):
                #print(f"I can reach vertex {v} with {w}")
                self.parent_edges[v] = w
        #print('parent weights:', end= ' ')
        #print(self.parent_edges)

    def spanningTree(self, V, adj):
        self.parent_edges = [-1 for i in range(V)]
        self.parent_edges[0] = 0
        self.included = set()
        #print('parent weights:', end= ' ')
        #print(self.parent_edges)
        for k in range(V):
            min_parent_edge = self.inf
            min_index = 0
            for i in range(V):
                if i not in self.included and self.parent_edges[i]<=min_parent_edge and self.parent_edges[i]!=-1:
                    min_parent_edge = self.parent_edges[i]
                    min_index = i
            self.included.add(min_index)
            self.update(min_index, adj)
        res = 0
        for w in self.parent_edges:
            res += w
        return res

test_cases = int(input())
for cases in range(test_cases):
    V,E = map(int, input().strip().split())
    adj = [[] for i in range(V)]
    for i in range(E):
        u, v, w = map(int, input().strip().split())
        adj[u].append([v, w])
        adj[v].append([u, w])
    ob = Solution()
    print(ob.spanningTree(V, adj))