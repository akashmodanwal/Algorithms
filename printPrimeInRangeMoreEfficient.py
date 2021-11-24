def printAll(n):
    arr = list(range(n+1))
    arr[1] = 0
    for i in range(2,n+1):
        if arr[i] == 0:
            continue
        print(i)
        for j in range(i*i,len(arr),i):
            arr[j] = 0
        
printAll(100)
