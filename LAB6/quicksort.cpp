#include<iostream>

using namespace std;

int main(){

    int a[] = {1, 10, 7, 70, 12};

    int n = sizeof(a)/sizeof(int);

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

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
    int n,m; cin >> n >> m;
    int a[n][m];
    int a2[n];
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    
    int cnt = 0;
    while(m>0){
        for(int i=0; i<n; i++){
            a2[i] = a[i][cnt];
            
        }
        qsort(a2, 0, n-1);
        for(int i=0; i<n; i++){
            a[i][cnt] = a2[i];
        }
        m--;
        cnt++;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
