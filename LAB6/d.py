def qsort1(a):
    l = []
    e = []
    g = []
    if len(a) > 1:
        pivot = a[0][2]
        for x in a:
            if x[2] < pivot: l.append(x)
            elif x[2] == pivot: e.append(x)
            elif x[2] > pivot: g.append(x)
        return qsort1(l)+e+qsort1(g)  
    else: return a
def qsort2(a):
    l = []
    e = []
    g = []
    if len(a) > 1:
        pivot = a[0][1]
        for x in a:
            if x[1] < pivot: l.append(x)
            elif x[1] == pivot: e.append(x)
            elif x[1] > pivot: g.append(x)
        return qsort2(l)+e+qsort2(g)  
    else: return a
def qsort3(a):
    l = []
    e = []
    g = []
    if len(a) > 1:
        pivot = a[0][0]
        for x in a:
            if x[0] < pivot:l.append(x)
            elif x[0] == pivot:e.append(x)
            elif x[0] > pivot:g.append(x)
        return qsort3(l)+e+qsort3(g)  
    else: return a
import time
from datetime import datetime
array=[]
n=int(input())
for i in range(n):
    x=input()
    array.append(x)
array.sort(key = lambda date: datetime.strptime(date, "%d-%m-%Y"))
for i in array:
    print(i)