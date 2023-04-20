#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j] || s[i] == s[j] + 32)  ++j;
  pi[i] = j;
 }
 return pi;
}

vector<int> kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size()) {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}


int main(){
    string s; cin>>s;
    int n; cin>>n;
    vector<string> nn;
    vector<string>cit;
    int max = 0;
    for(int i=0; i<n; i++){
        string city; cin>>city;
        string str = to_lowcase(city) + '#' + s;
        vector<int> v2 = prefix_function(str);
        if(max<v2[v2.size() - 1]) max = v2[v2.size() - 1];
        nn.push_back(city);
    }

    for(int i=0; i<nn.size(); i++){
        string str = to_lowcase(nn[i]) + '#' + s;
        vector<int> v2 = prefix_function(str);
        if(v2[v2.size() - 1] == max){
            cit.push_back(nn[i]);
        }
    }
    
    cout << cit.size() << endl;
    for(int i=0; i<cit.size(); i++){
        cout << cit[i] << endl;
    }
}