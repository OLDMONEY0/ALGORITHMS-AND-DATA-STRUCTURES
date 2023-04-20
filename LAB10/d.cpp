#include <bits/stdc++.h>

using namespace std;
vector<int>vec[6666];
int toRed[6666];

int BFS(int v) {
  vector<bool> visited(1e5, false);
  vector<int>d(6666,0);
  queue<int>l;
  l.push(v);
  visited[v] = true;
  d[v]=0;

  while (!l.empty()) {
    int curr = l.front();
    l.pop();
    if(toRed[curr] == 1) return d[curr];
    for(auto m: vec[curr]){
        if(!visited[m]){
            d[m] = d[curr] + 1;
            visited[m] = true;
            l.push(m);
        }
    }
  }
  return -1;
}


int main()
{
    int n,m,q; cin>>n>>m>>q;
    int cnt=0;
    for(int i=0; i<m; i++){
        int from, to;
        cin >>from>>to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }
    for(int i=0; i<q; i++){
        int q1,vert; cin>>q1>>vert;
        if(q1 == 1){
            cnt=1;
            toRed[vert] = 1;
        }
        else{
            if(cnt == 0) cout << -1 << endl;
            else cout << BFS(vert) << endl;
        }
    }
    
}