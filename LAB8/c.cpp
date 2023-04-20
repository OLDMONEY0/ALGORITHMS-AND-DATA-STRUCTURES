#include <bits/stdc++.h>
using namespace std;

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
int main(){
    string str; cin >> str;
    int n; cin >> n;
    vector<int> v;
    map<int, int> invec;
    for(int i = 0; i < str.size(); i++){
        invec[i] = 1;
    }
    while(n--){
        string s; cin >> s;
        vector<int> vec = search(s, str);
        for(int i=0;i<vec.size();i++){
            for(int w=vec[i]; w<s.length()+vec[i]; w++){
                invec[w] = 0;
            }
        }
    }
    bool find=false;
    for(auto c : invec){
        if(c.second==1){
            cout << "NO";
            find=true;
            break;
        }
    }
    if(!find){
        cout << "YES";
    }
}