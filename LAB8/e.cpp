#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    long long a[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        if(i == 0){
            cout<<char(a[i]/pow(2, i) + 97);
        }
        else{
            cout<<char((a[i] - a[i - 1])/pow(2, i) + 97);
        }
    }
}