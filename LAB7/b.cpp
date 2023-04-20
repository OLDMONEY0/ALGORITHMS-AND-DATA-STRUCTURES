#include <bits/stdc++.h>
using namespace std;
void merge(int *,int, int , int );
void merge(int *arr,int *arr2, int n, int m)
{
    int i, j;
    vector<int> v;
    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (arr[i] < arr2[j]) {
            v.push_back(arr[i]);
            i++;
        }
        else  {
            v.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) {
        v.push_back(arr[i]);
        i++;
    }
    while (j < m) {
        v.push_back(arr2[j]);
        j++;
    }
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}


int main()
{
    int n; cin>>n;
    int a1[n];
    
    for(int i=0; i<n; i++){
        cin>>a1[i];
 
    }
    
    int m; cin>>m;
    int a2[m];
    for(int i=0; i<m; i++){
        cin>>a2[i];
  
    }
    merge(a1,a2,n,m);
}