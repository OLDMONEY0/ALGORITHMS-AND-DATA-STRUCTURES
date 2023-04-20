#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000008;
vector <vector<int> > d(656, vector<int> (656, maxn));
vector <vector<int> > a(656, vector<int> (656, maxn));
int ans = 0;
int n;
vector<int> arr;

void solve(int k) {
    ans = 0;
    for (int i = 0; i < arr.size(); ++i){
            for (int j = 0; j < arr.size(); ++j) {
                a[arr[j]][k] = min(a[arr[j]][k], a[arr[j]][arr[i]] + a[arr[i]][k]);
            }
    }

    for (int i = 0; i < arr.size(); ++i){
            for (int j = 0; j < arr.size(); ++j){
                a[k][arr[j]] = min(a[k][arr[j]], a[k][arr[i]] + a[arr[i]][arr[j]]);
            }
    }

  

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            a[arr[i]][arr[j]] = min(a[arr[i]][arr[j]], a[arr[i]][k] + a[k][arr[j]]);
            if (a[arr[i]][arr[j]] < maxn and a[arr[i]][arr[j]] > ans){
                ans = a[arr[i]][arr[j]];
            }
        }
    }

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
            if (d[i][j] == 0 and i != j) d[i][j] = maxn;
            if (i == j) a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        arr.push_back(x);
        for (int j = 0; j < arr.size(); ++j) {
        a[x][arr[j]] = d[x][arr[j]];
        a[arr[j]][x] = d[arr[j]][x];
        } 
        solve(x);
        cout << ans << endl;
    }
}