def sumOfSubsetZero(arr,n):
    
    dict = {}
    dict[0] = 1
    sum =0
    for i in arr:
        sum+=i
        if sum in dict:
            return True
        else:
            dict[sum] = 1
    
    return False
    
arr = [6,-1,2,12,-1]

print(sumOfSubsetZero(arr,len(arr)))
