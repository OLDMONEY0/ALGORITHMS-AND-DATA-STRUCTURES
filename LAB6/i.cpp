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
    string a; cin>>a;
    string n = "";
    int arr[a.size()];
    for (int i=0; i<a.size(); i++){
        arr[i] = toint(a[i]); 
    }
    qsort(arr, 0, a.size() - 1);
    for (int i=0; i<a.size(); i++){
        n+=char(arr[i]);
    }
    
    cout << n;
}