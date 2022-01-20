def solve(mat):
    rows = []
    for i in mat:
        rows.append(sorted(i))
    col = []
    for i in range(n):
        one = []
        for j in range(n):
            one.append(mat[j][i])
        col.append(sorted(one))
    rows = rows+col
    print(rows)
    for i in rows:
        for j in range(1,len(mat[0])+1):
            if j not in i:
                return False
    return True

            

n = int(input())
mat = []
for _ in range(n):
    r = list(map(int,input().split()))
    mat.append(r)
print(solve(mat))

