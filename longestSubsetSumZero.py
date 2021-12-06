def longestSubsetSumZero(arr,n):
    dict ={}
    dict[0] = -1
    preSum = 0
    ans = 0
    for i in range(n):
        preSum += arr[i]
        if preSum not in dict:
            dict[preSum] = i
        else:
            ans = max(ans,i-dict[preSum])
    return ans
    
arr = [3,2,4,-4,-5]
print(longestSubsetSumZero(arr,len(arr)))


