#include <bits/stdc++.h>
using namespace std;
long long D=256, m = 1e9, p=31, N = 1e5;
vector<long long> Hash1(string txt,int len){
        int q = 1e9+7;
        int p = 31;
        vector<long long> rethash(len);
        long long p_power = 1;
        rethash[0] = (txt[0] - 'a' + 1)*p_power%q;
        p_power = (p_power*p) %q;
        for(int i=1; i<txt.size(); i++){
            rethash[i] = (txt[i] - 'a' + 1)*p_power%q;
            rethash[i] = (rethash[i] + rethash[i-1])%q;
            p_power = (p_power*p) %q;
        }
        return rethash;
    }
long long Hash(string txt,int len){
    int q = 1e9+7;
    int p = 31;
    int hash_so_far = 0; 
    long long p_power = 1;
    const int n = len;
    for(int i=0; i<n; ++i){
        hash_so_far = (hash_so_far + (txt[i] - 'a' + 1)*p_power) %q;
        p_power = (p_power*p)%q;
    }
    return hash_so_far;
}


vector<int> search(string pat, string txt){
    int q = INT_MAX;
    int p = 31;
    int M = pat.length();
    int N = txt.length();
    vector <int> ans;
    int m = 1e9+7;
    long long h = Hash(pat,M);
    vector<long long> hashes = Hash1(txt,N);
    for (int i = 0; i <= N - M+1; i++) {
        long long hashdif = hashes[i + M - 1];
        if(i != 0) hashdif -= hashes[i-1];
        if(hashdif < 0) hashdif += m;
        if(i!=0) h = (h*p)%m;
        if(h == hashdif){
            ans.push_back(i);
        }
    }return ans;
}


string findi(vector<string> v){
    string maxn="";
    int mx=0, l;
    long long h1=0, p_power1 = 1;
    int a[N] = {0};
    for(int i=0; i<v[1].size(); i++){
        long long h =0;
        h1 = (v[1][i] - 'a' +1)*p_power1%m; 
        long long p_power=1;
        pair<long long, string> hstr;
        for(int j=v[0].size()-1; j>=0; j--){
            h = (v[0][j] - 'a' + 1)*p_power%m;
            if(h == h1) a[j +1] = a[j] + 1; else a[j+1] = 0;
            if(a[j+1]>mx) {
                mx = a[j+1];
                l = j-mx+1;
            }
        }
    }
    if(mx==0)return "";
    return v[0].substr(l, mx);


}

int main(){
    int n; cin>>n;
    string str, s;
    if(n!=0)n--; 
    cin >> str;
    while(n--){
        cin >> s;
        vector<string> vec;
        vec.push_back(str); 
        vec.push_back(s);
        str = findi(vec);
    }
    cout << str;
}
