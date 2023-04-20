#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        int from, to;
        cin>>form>>to;
        from--; to--;
        matrix[from][to] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}