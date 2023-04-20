#include <bits/stdc++.h>
using namespace std;
void f(string t){
    unordered_map<long long,int>d;
    vector<vector<long long>>l;
    size_t n = t.size();
    long long h[n];
    long long q = 1e15;
    long long p = 31;
    for(int j=0; j<n; j++){
        long long h_s = 0;
        for(int i = j; i < n; i++){
            h_s = (h_s * 31 + t[i]) % q;
            if(d.find(h_s) == d.end()){
                l.push_back({j, i});
            }
            d[h_s] = 1;
        }
    }
    cout << l.size();
}
    

int main(){
   string s; cin>>s;
   f(s);
}

