#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int main() {
    int n; cin>>n;
    vector<vector<int>>g(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
        }
    }
    
  int selected[n];

  memset(selected, false, sizeof(selected));
  selected[0] = true;
  int no_edge = 0;
  int x,y;
  int cnt=0;
  while (no_edge < n - 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (int i = 0; i < n; i++) {
      if (selected[i]) {
        for (int j = 0; j < n; j++) {
          if (!selected[j]) {
            if (min > g[i][j]) {
              min = g[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    selected[y] = true;
    cnt+=g[x][y];
    no_edge++;
  }
  
  cout << cnt;

  return 0;
}