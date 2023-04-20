#include <cstring>
#include <bits/stdc++.h>
using namespace std;

#define INF 9999999
int main() {
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
      cin>>arr[i];
  }
  vector<vector<int>> G(n, vector<int>(n,0));
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          if(i==j) G[i][j] = INF;
          else G[i][j] = arr[i] + arr[j];
      }
  }
  int no_edge=0;
  int selected[n];

  memset(selected, false, sizeof(selected));
  selected[0] = true;
  int cnt=0;
  int x,y;
  while (no_edge < n - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < n; i++) {
      if (selected[i]) {
        for (int j = 0; j < n; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
   cnt +=G[x][y];
    selected[y] = true;
    no_edge++;
  }
  cout << cnt;
  return 0;
}