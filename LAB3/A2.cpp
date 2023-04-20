#include <bits/stdc++.h>
using namespace std;

int bin(int arr[], int n, int t){
    int l = 0, h = n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] == t){
            return mid;
        }
        else if (arr[mid] < t){
            l=mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}

int main(){
    int x; cin>>x;
    int rows[x];
    for(int i=0; i<x; i++){
        cin>>rows[i];
    }

    int n,m; 
    cin >> n >> m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        if(i%2 == 1){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        else{
            for(int j = m-1; j>=0; j--){
                cin>>arr[i][j];
            }
        }
    }

    for(int i=0; i<x; i++){
        int ind = 0;
        while(arr[ind][0]>rows[i]){
            ind++;
        }
        int a = bin(arr[ind], m, rows[i]);
        if(a!=-1){
            if(ind%2==0) cout<<ind<<" "<< m-a-1;
            else cout<<ind<<" "<<a;
        }
        else{
            cout<<-1;
        }
        cout<<endl;

    }
}