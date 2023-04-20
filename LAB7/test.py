def merge_sort(array):
    if len(array)<=1:return array

    mid=len(array)//2
    l,r=merge_sort(array[:mid]), merge_sort(array[mid:])
    return merge(l,r)
def merge(l,r):
    res=[]
    left_pointer=right_pointer=0
    while left_pointer<len(l) and right_pointer<len(r):
        if l[left_pointer]<r[right_pointer]:
            res.append(l[left_pointer])
            left_pointer+=1
        else:
            res.append(r[right_pointer])
            right_pointer+=1
    res.extend(l[left_pointer:])
    res.extend(r[right_pointer:])
    return res
for _ in range(int(input())):
    x=input().split(" ")
    size=[]
    dict={}
    for i in x:
        l=len(i)
        if l not in dict:
            dict[l]=[i]
            size.append(l)
        else:dict[l].append(i)
    size=merge_sort(size)
    for i in size:
        print(*dict[i],end=' ')
    print()