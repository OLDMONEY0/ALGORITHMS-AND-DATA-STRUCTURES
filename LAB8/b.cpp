#include <bits/stdc++.h>
using namespace std;
unordered_map <size_t, size_t> m;
size_t cnt = 0;
void count(string t, string s){
    size_t t_size = t.size();
    size_t s_size = s.size();
    long long h[t_size];
    long long p[t_size];
    long long q = 2147483647;//some big prime number
    p[0] = 1;
    for(size_t i = 1; i < max(t_size, s_size); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < t_size; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_s = 0;
    for(size_t i = 0; i < s_size; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(size_t i = 0; i + s_size - 1 < t_size; i++){
        long long d = h[i + s_size - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if(d == (h_s * p[i]) % q){
            m[i]++;
            if(m[i] > 1) cnt++;
        }
    }
}
int main(){
    string s1, s2, patt;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, patt);
    count(s1, patt);
    count(s2, patt);
    cout << cnt;
    return 0;
}