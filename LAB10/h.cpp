#include<bits/stdc++.h>

using namespace std;
void dfs(vector<vector<char>>&grid,int i,int j){
        if(i>grid.size()-1 || j>grid[0].size()-1|| i<0 ||j<0 || grid[i][j]!='1'){
            return ;
        }
        grid[i][j]='2';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
    }
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(grid,i,j);
            }
        }
    }
    return count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    int cnt = numIslands(v);
    cout << cnt;
}