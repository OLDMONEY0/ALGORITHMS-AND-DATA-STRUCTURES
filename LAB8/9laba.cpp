#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat,long long M ,long long* lps);
vector<long long> v;
void KMPSearch(string pat, string txt)
{
    long long M = pat.size();
    long long N = txt.size();

    long long lps[M];
    computeLPSArray(pat, M, lps);
 
    size_t i = 0;
    size_t j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            v.push_back(i-j);
            j = lps[j - 1];
            
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void computeLPSArray(string pat,long long M,long long* lps)
{
    long long len = 0;
 
    lps[0] = 0;
    size_t i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
 
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    string txt; cin>>txt;
    string c = txt;
    string pat; cin>>pat;
    int cnt = 1;
    if(txt.size() < pat.size()){
        while(c.size()<pat.size()){
            cnt++;
            c+=txt;
        }
        KMPSearch(pat, c);
        if(!v.empty()){
            cout << cnt;
        }
        else{
            cnt++;
            c+=txt;
            KMPSearch(pat, c);
            if(!v.empty()) cout << cnt;
            else cout << -1;
        }
    }
    else{
        KMPSearch(pat, c);
        if(v.empty()) cout << -1;
        else cout<<1;
    }

}
    
    
    
    
    
    
    
    
    
    
    
    
    // int cnt=1;
    //if(txt.size() < pat.size()){
      //  while(v.empty()){
        //    c+=txt;
          //  cnt++;
            //KMPSearch(pat, c);
            //if(c.size() > 2 * pat.size()){
              //  cout << -1;
                //return 0;
            //}
        //}
        //cout << cnt;
    //}
    //else{
       // KMPSearch(pat, c);
        //if(v.empty()) cout << -1;
        //else cout<<1;
    //}
    //return 0;