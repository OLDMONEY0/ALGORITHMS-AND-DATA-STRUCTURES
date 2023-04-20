#include<bits/stdc++.h>

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

int toint(char a){
    int num = a - 0;
    return num;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    qsort(arr, 0, n-1);
    int diff = abs(arr[0] - arr[1]);
    for (int i=0; i<n-1; i++){
        if(diff >= abs(arr[i] - arr[i+1])){
            diff = abs(arr[i] - arr[i+1]);
        }
    }
    
    for(int i=0; i<n-1; i++){
        if(diff == abs(arr[i] - arr[i+1])){
            cout << arr[i] << " " << arr[i+1] << " ";
        }
    }
    
    
    
}