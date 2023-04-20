#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    for (int i=0; i<n; i++){
        string m = "";
        stack<char> s;
        int cnt = 0;
        long long mem; cin>>mem;
        while(mem>0){
            cnt++;
            m+=(mem%2 + '0');
            mem/=2;
        }
        for(int j = 0; j < cnt; j++){
            if(!s.empty()){
                if(s.top()=='0' and m[j]=='1'){
                    s.pop();
                }else{
                    s.push(m[j]);
                }
            }else{
                s.push(m[j]);
            }
        }
        if(s.empty()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}