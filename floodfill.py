# runs fine locally, 
# but gets runtime error on geeksforgeeks

from queue import Queue

# I push to the queue sub-lists of:
# position x - position y - time affected

def printArr(arr):
    for i in arr:
        print (i)

def printQueue(q):
    q2 = Queue()
    while q.qsize():
        x=q.get()
        print(x)
        q2.put(x)
    while q2.qsize():
        q.put(q2.get())

def floodFill(arr, N, M):
    print("I am flood fill")
    q = Queue()
    # initialize the queue with all the affected positions
    for x in range(len(arr)):
        for y in range(len(arr[x])):
            if arr[x][y][0]==0: ######
                curr  = [x, y, 0]
                q.put(curr)
    print("I initialize the queue as:")
    printQueue(q)
    while q.qsize():
        curr = q.get()
        print(f"I dequeue the: {curr}", end=' ')
        x = curr[0]
        y = curr[1]
        time = curr[2]
        # if affected 'later' than i will affect it or not affected yet
        if (arr[x][y][0]==0 and arr[x][y][1]>time) or arr[x][y][0]==1 or arr[x][y][1]==0: ###
            print("useful")
            arr[x][y][0]=0
            arr[x][y][1]=time
            # I begin a flood to the neighbours
            if x-1>=0:
                q.put([x-1, y, time+1])
            if x+1<N:
                q.put([x+1, y, time+1])
            if y-1>=0:
                q.put([x, y-1, time+1])
            if y+1<M:
                q.put([x, y+1, time+1])
        # if affected before me
        else: #arr[x][y][0]==1 and arr[x][y][1]<=time:
            print("not useful")
            pass

def findMax(arr):
    printArr(arr)
    max = 0
    for x in range(len(arr)):
        for y in range(len(arr[x])):
            if arr[x][y][1]>max:
                max = arr[x][y][1]
    return max

def solveOne():
    NM = list(input().split(' '))
    N = int(NM[0])
    M = int(NM[1])
    arr = []
    for i in range(N):
        arr.append([[int(x), 0] for x in list(input().split(' '))])
    floodFill(arr, N, M)
    print(findMax(arr))

def solve():
    T = int(input())
    for i in range(T):
        solveOne()

solve()