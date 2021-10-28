def printSubSetLexico(arr,temp,pos,i,n):
    if i==n+1:
        return
    print(temp[:pos])
    for j in range(i,n):
        temp[pos] = arr[j]
        printSubSetLexico(arr,temp,pos+1,j+1,n)
        
printSubSetLexico([1,2,3,4],[0]*4,0,0,4)
