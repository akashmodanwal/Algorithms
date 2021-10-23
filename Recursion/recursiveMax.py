def maxR(arr,i,maxm,n):
    if i==n:
        return maxm
    if maxm>arr[i]:
        return maxR(arr,i+1,maxm,n)
    return maxR(arr,i+1,arr[i],n)
    
arr = [111111,2,3,4,5,6,7999,1,2,-123312,2414,0,123,23,34,6,3,1111112111]
n=len(arr)

print(maxR(arr,0,-9999,n))
