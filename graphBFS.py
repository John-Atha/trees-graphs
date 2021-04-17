from queue import Queue
class Solution:

    def bfsOfGraph(self, V, adj):
        seen = [False for i in range(V)]
        curr = 0
        q = Queue()
        answer = []
        q.put(curr)
        while q.qsize():
            x = q.get()
            if not seen[x]:
                seen[x]=True
                answer.append(x)
                for node in adj[x]:
                        q.put(node)
        return answer