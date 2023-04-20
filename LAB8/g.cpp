#include <bits/stdc++.h>
using namespace std;
#define d 31
int cnt = 0;
vector <int> v;
void search(string pat, string txt)
{   
    size_t M = pat.size();
    size_t N = txt.size();
    size_t i, j;
    size_t p = 0; 
    size_t t = 0; 
    size_t h = 1;
    long long q = 1e9;
 
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) %q;
        t = (d * t + txt[i]) %q;
    }
    for (i = 0; i <= N - M; i++) {
 
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
 
            if (j == M){
                cnt++;
            }
        }
 
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            
            if (t < 0)
                t = (t + q);
        }
    }
    v.push_back(cnt);
    cnt = 0;
}
int main()
{
    string s; cin>>s;
    int n; cin>>n;

    for(int i=0; i<n; i++){
        string sum = "";
        int x,y; cin>>x>>y;
        for(int i=x-1; i<y; i++){
            sum+=s[i];
        }
        search(sum, s);
    }
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
}


void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}