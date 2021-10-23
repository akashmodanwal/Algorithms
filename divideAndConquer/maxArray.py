def maxR(arr):
    if len(arr)==1:
        return arr[0]
    mid = len(arr)//2
    return max(maxR(arr[:mid]),maxR(arr[mid:]))
    
    
arr = [1,2,3,4,5,6,7,8,9,0]
print(maxR(arr))
