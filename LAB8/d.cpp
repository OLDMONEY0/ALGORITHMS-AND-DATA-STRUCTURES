#include<bits/stdc++.h>
using namespace std;

unordered_map <size_t, size_t> mp;
size_t cnt = 0;

void count(string t, string s){
    size_t n = t.size();
    size_t m = s.size();
    long long h[n];
    long long p[n];
    long long q = 1e9;
    p[0] = 1;
    for(size_t i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_s = 0;
    for(size_t i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if(d == (h_s * p[i]) % q){
            mp[i]++;
            if(mp[i] > 1) cnt++;
        }
    }
}
int main(){
    while(true){
        cnt = 0;
        int n; 
        cin >> n;
        if(n == 0) break;
        string arr[n];
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            arr[i] = s;
        }
        string s2;cin >> s2;
        int mx = 0;
        vector<string> v;
        for(int i = 0; i < n; i++){
            mp.clear();
            cnt = 0;
            count(s2, arr[i]);
            count(s2, arr[i]);
            if(cnt > mx){
                v.clear();
                v.push_back(arr[i]);
                mx = cnt;
            }
            else if(cnt == mx) v.push_back(arr[i]);
        }
        cout << mx << endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << endl;
        }
    }
}