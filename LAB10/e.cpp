#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(6000, vector<int>(6000,0));
int check(int a, int b){
    a--; b--;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            if(v[a][b]==1) return 1;
        }
    }
    return 0;
}
int main() {
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    for(int i=0; i<q ;i++){
        int a,b,c; cin>>a>>b>>c;
        if(check(a,b) == 1 and check(a,c) == 1 and check(b,c) == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}