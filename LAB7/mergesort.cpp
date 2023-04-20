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

void merge(int a[], int l1, int r1, int l2, int r2){
    int i = l1;
    int i1 = l1;
    int i2 = l2;
    while(i1 <= r1 && i2<=r2){
        if(a[i1] < a[i2]){
            a[i] = a[i1];
            l1++;
        }
        else{
            a[i] = a[i2];
            l2++;
        }
        i++;
    }
    if(i1 >= r1){
        for(int j=i2; j <=r2; j++){
            a[i] = a[j];
            i++;
        }
    }

    if(i2 >= r2){
        for(int j=i1; j <=r1; j++){
            a[i] = a[j];
            i++;
        }
    }
}





void msort(int a[], int l; int r){
    if(l<r){
        int m = l+(r-l) / 2;
        msort(a,l,m);
        msort(a,m+1, r);
    }

}

