def sumOfSubsetIsK(arr,k,n):
    
    dict = {}
    dict[0] = 1
    sum =0
    for i in arr:
        sum+=i
        if sum - k in dict:
            return True
        else:
            dict[sum] = 1
    
    return False
    
arr = [6,1,12,3,-1]

print(sumOfSubsetZero(arr,5,len(arr)))
