#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    vector<int>v;
    int cnt = 0;
    while(a!=b){
        v.push_back(b);
        cnt++;
        if(a>b){
            b++;
        }
        else{
            if(b%2==1){
                b++;
            }
            else{
                b/=2;
            }
        }
    }
    cout << cnt<<endl;
    for(int i=cnt - 1; i>=0; i--){
        cout << v[i] << " ";
    }
}