def longestSubsetSumAsK(arr,n,k):
    dict ={}
    dict[0] = -1
    preSum = 0
    ans = 0
    for i in range(n):
        preSum += arr[i]
        if preSum - k  in dict:
            ans = max(ans,i-dict[preSum - k])
        if preSum not in dict:
            dict[preSum] = i
            
    return ans
    
arr = [3,2,1,1,1,1,1,1]
print(longestSubsetSumAsK(arr,len(arr),6))


