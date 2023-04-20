def toH(s):
    l=len(s)
    module=10**9+7
    mod=[1]*l
    for i in range(1,l):
       mod[i]=(mod[i-1]*11)%module
    hold=0
    for i in range(l):
        hold=(hold+((int(s[i])-47)*mod[i])%module)%module
    return str(hold)
hashs={}
inv=[]
arr=[]
for _ in range((int(input()))*2):
    x=input()
    arr.append(x)
    hashs[x]=toH(x)
    inv.append(x)
i=0

for index in (arr):
    if(hashs[index] in inv and i<len(arr)//2):
        i+=1
        print("Hash of string ",index," is ",hashs[index])