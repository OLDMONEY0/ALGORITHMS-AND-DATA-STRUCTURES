#include<iostream>

using namespace std;

int partition(int a[], int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j=low; j<high; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);

    return i+1;
}

void qsort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
    
        qsort(a, low, pivot - 1);
        qsort(a, pivot+1, high);
    }
}

int main(){
    int n,m; cin>>n>>m;
    int a1[n];
    int a2[m];
    
    for(int i=0; i<n; i++){
        cin>>a1[i];
    }
    for(int i=0; i<m; i++){
        cin>>a2[i];
    }
    qsort(a1,0,n-1);
    qsort(a2,0,m-1);
    int cnt1 = 0;
    int cnt2 = 0;
    while(cnt1 < n and cnt2 < m){
        if (a1[cnt1] == a2[cnt2]){
            cout << a1[cnt1] << " ";
            cnt1++;
            cnt2++;
        }
        else if(a1[cnt1] < a2[cnt2]){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
}