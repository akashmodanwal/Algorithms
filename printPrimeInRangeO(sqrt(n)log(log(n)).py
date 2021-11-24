def printAll(n):
    import math
    sqn = int(math.sqrt(n))
    arr = list(range(n+1))
    arr[1] = 0
    for i in range(2,sqn+1):
        if arr[i] == 0:
            continue
        for j in range(i*i,len(arr),i):
            arr[j] = 0
    ans = []
    for i in arr:
        if i != 0:
            ans.append(i)
    print(ans)
printAll(50)
