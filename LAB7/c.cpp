#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}


int main()
{
    int n,m; cin>>n>>m;
    int a1[n];
    int a2[m];
    
    for(int i=0; i<n; i++){
        cin>>a1[i];
    }
    for(int i=0; i<m; i++){
        cin>>a2[i];
    }
    
    merge_sort(a1, 0, n-1);
    merge_sort(a2, 0, m-1);
    
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