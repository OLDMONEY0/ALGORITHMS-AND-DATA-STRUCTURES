def bs(a, t, n):
    l, h = 0, n-1
    while(l<=h):
        mid = (l+h)//2
        if a[mid] == t:return mid
        elif a[mid]>t:h = mid - 1
        else:l = mid + 1
    return -1
n = int(input())
a = list(map(int, input().split()))
t = int(input())
if bs(a,t,n) == -1:
    print("No")
else:
    print("Yes")