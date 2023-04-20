#include <bits/stdc++.h>
using namespace std;
 
#define MAX_NODES 100005
int parent[MAX_NODES];
int size_set[MAX_NODES];

void make_set(int v)
{
    parent[v] = v;
    size_set[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
 

    return parent[v]
           = find_set(parent[v]);
}
 

void union_set(int a, int b)
{

    a = find_set(a);
    b = find_set(b);
 
    if (a != b) {
 
        if (size_set[a] < size_set[b])
            swap(a, b);

        parent[b] = a;

        size_set[a] += size_set[b];
    }
}
 

string check(int a, int b){
    a = find_set(a);
    b = find_set(b);
 
    return (a == b) ? "YES" : "NO";
}
 
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0; i<n; i++){
        make_set(i+1);
    }
    for(int i=0; i<m; i++){
        int from, to; cin>>from>>to;
        union_set(from, to);
    }
    int q=1;
    int from1, to1; cin>>from1 >> to1;
    cout << check(from1, to1);
    return 0;
}