#include <bits/stdc++.h>
using namespace std;
void merge(vector<vector<int>> &a,int, int , int );


bool comp(vector<int> a1, vector<int> a2){

    if((accumulate(a1.begin(), a1.end(), 0)) == (accumulate(a2.begin(), a2.end(), 0))){
        int i=0;
        while(i<a1.size()){
            if(a1[i] == a2[i]){
                i++;
            } else {
                return a1[i] < a2[i];
            }
        }
    }
    return (accumulate(a1.begin(), a1.end(), 0)) > (accumulate(a2.begin(), a2.end(), 0));
}

void merge_sort(vector<vector<int>> &a, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}

void merge(vector<vector<int>> &a, int low, int high, int mid)
{   vector<vector<int>> vec;
    int i, j;
    i = low;
    j = mid + 1;
    while(i <= mid && j <= high){
        if((comp(a[i], a[j]))){
            vec.push_back(a[i]);
            i++;
        } else {
            vec.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid){
        vec.push_back(a[i]);
        i++;
    }
    while(j <= high){
        vec.push_back(a[j]);
        j++;
    }
    
    for(i=low; i <= high;i++ ){
        a[i] = vec[i-low];
        
    }
}
int main()
{
   int n,m; cin>>n>>m;
   int a[n][m];
   vector<vector<int>>v;
   
   for(int i=0; i<n; i++){
       int sum = 0;
       vector<int>c;
       for(int j=0; j<m; j++){
           cin>>a[i][j];
           c.push_back(a[i][j]);
       }
       v.push_back(c);
   }
   
    merge_sort(v,0,v.size()-1);
    for(auto c: v){
        for(auto g: c){
            cout << g << " ";
        }
        cout << endl;
    }
    return 0;
}