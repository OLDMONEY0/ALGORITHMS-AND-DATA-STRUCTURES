#include <iostream>
#include <vector>

using namespace std;
vector<int>v;
void computeLPSArray(string pat, int M, int* lps);
void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    int lps[M];
    computeLPSArray(pat, M, lps);
 
    int i = 0;
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            v.push_back(i - j);
            j = lps[j - 1];
            
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
}


void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
 
    lps[0] = 0;
    int i = 1;
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
    string text, pattern; cin>>text>>pattern;
    string str = text + text;;
    KMPSearch(pattern, str);
    if(!v.empty()){
        for(int i=0; i<v.size(); i++){
            cout << text.size() - v[i];
        }
    }
    else cout << -1;
    return 0;
}