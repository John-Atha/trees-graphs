# T test cases
# in each one, given a tree, 
#   find the abs difference of sums of the nodes values
#   at odd and even level

from queue import Queue

def printQueue(q):
    print("Queue:", end=' ')
    q2 = Queue()
    while q.qsize():
        x = q.get()
        print(x, end=' ')
        q2.put(x)
        print()
    while q2.qsize():
        q.put(q2.get())

def printSets(even, odd):
    print(f"Odd: {odd}")
    print(f"Even: {even}")

def addEdge(d, a, b):
    d[a][1].append(b)
    d[b][1].append(a)
    #print(d)

def treeInit(d, N):
    nodesValues = list(map(lambda x: int(x), list(input().split(' '))))
    for i in range(N):
        d[i]=[nodesValues[i], []]
    for i in range(N-1):
        edge = list(map(lambda x: int(x), list(input().split(' '))))
        addEdge(d, edge[0]-1, edge[1]-1)
    #print(d)

def BFS(d, even, odd):
    q = Queue()
    seen = set()
    q.put((1, 1))
    #printQueue(q)
    odd.add(1)
    #printSets(even, odd)
    while q.qsize():
        currL = q.get()
        #print(f"I popped:{currL}")
        par = currL[1]
        curr = currL[0]
        if curr not in seen:
            seen.add(curr)
            if par!=curr:
                if par in odd:
                    even.add(curr)
                else:
                    odd.add(curr)
            #printSets(even, odd)
            for node in d[curr][1]:
                q.put((node, curr))
                #print(f"I put ({node}, {curr}) in the queue")
        
def diffCompute(tree, even, odd):
    sum1 = 0
    sum2 = 0
    for v in even:
        sum1+=tree[v][0]
    for u in odd:
        sum2+=tree[u][0]
    print(abs(sum1-sum2))

def solveOne():
    N = int(input())
    tree = {}
    even = set()
    odd=set()
    treeInit(tree, N)
    BFS(tree, even, odd)
    diffCompute(tree, even, odd)

def solveAll():
    T = int(input())
    for i in range(T):
        solveOne()

solveAll()