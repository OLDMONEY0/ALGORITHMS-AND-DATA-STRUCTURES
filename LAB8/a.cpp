#include <bits/stdc++.h>
#define ll long long
using namespace std;

string Hash(string s){
    size_t n = s.size();
    long long p[n];
    long long h[n];
    long long q = 1e9 + 7;
    p[0] = 1;
    for(size_t i = 1; i < n; ++i){
        p[i] = (p[i - 1] * 11) % q;
    }
    for(size_t i = 0; i < n; ++i){
        h[i] = ((s[i] - 47) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    stringstream ss;
    ss << h[n-1];
    string str = ss.str();
    return str;
}

int main()
{
    int n; cin>>n;
    string a[n*2];
    map<string , string> mp;
    map<string , int> check;
    for(int i=0; i<n*2; i++){
        string s; cin>>s;
        a[i] = s;
        check.insert({s, 1});
        mp.insert({s, Hash(s)});
    }
    int cnt = 0;
    for(int i=0; i<n*2; i++){
        if(check[mp[a[i]]] == 1){
            cnt+=1;
            cout<<"Hash of string \""<<a[i]<<"\" is "<<mp[a[i]]<<endl;
            if(cnt==n){
               break;
            }
        }
    }
}