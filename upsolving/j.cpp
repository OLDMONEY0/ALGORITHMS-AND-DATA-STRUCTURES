#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a;
    int search; cin>>search;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int elem; cin>>elem;
        a.push_back(elem);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(binary_search(a.begin(), a.end(), search - a[i])){
            cout << a[i] << " " << search - a[i];
            break;
        }
    }
}