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

int toint(char a){
    int num = a - 0;
    return num;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for ( int i=0; i<n; i++){
        char a; cin>>a;
        arr[i] = toint(a);
    }
    char a2; cin>>a2;
    for ( int i=0; i<n; i++){
        if (toint(a2) < arr[i]){
            cout << char(arr[i]);
            break;
        }
    }
    if (toint(a2) >= arr[n-1]){
        cout << char(arr[0]);
    }
    
}