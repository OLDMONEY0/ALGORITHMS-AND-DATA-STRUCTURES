#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j]) ++j;
  pi[i] = j;
 }
 return pi;
}

int main(){
    string txt; cin>>txt;
    vector<int> v = prefix_function(txt);
    int cnt = 0;
    for(int i = 0; i < v.size()-1; i++){
        int cn = i + 1 - v[i];
        if(v[i] % cn == 0 && ((i+1)/cn) % 2 == 0){
            cnt++;
        }
    }
    cout << cnt;
}