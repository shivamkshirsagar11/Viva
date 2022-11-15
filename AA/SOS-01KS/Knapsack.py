def Knapsack(p,w,c,items):
    memo = [[None for i in range(c+1)]for j in range(items+1)]
    for i in range(items+1):
        for j in range(c+1):
            if i==0 or j==0:memo[i][j] = 0
            elif j >= w[i-1]:
                memo[i][j] = max(memo[i-1][j],memo[i][j-w[i-1]] + p[i-1])
            else:
                memo[i][j] = memo[i-1][j]
    return memo

def Subarr(arr,weight):
    i = len(arr)-1
    j = len(arr[0])-1
    x = [0 for k in range (i)]
    while(i>0 and j>0):
        if arr[i][j] == arr[i-1][j]:
            x[i-1] = 0
            i = i -1 
        else:
            x[i-1] = 1
            i = i - 1
            j = j - weight[i]
    return x