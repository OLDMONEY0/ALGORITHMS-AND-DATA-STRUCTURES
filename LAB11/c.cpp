#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[1005],b[1005];
int n,m,x,y,z,i,j,d[1005];
typedef pair<int,int>ii;

void prim(int u){
  int sum=0;
  for(i=1;i<=n;i++)
    d[i]=10e9;
  d[u]=0;
  priority_queue<ii> q;
  q.push(ii(0,u));
  while (!q.empty()) {
    ii t=q.top();
    q.pop();
    int u=t.second,du=-t.first;
    if(du!=d[u]) continue;
    sum=sum+d[u];
    d[u]=0;
   
    for (i=0;i<a[u].size();i++){
      int v=a[u][i];
      if (d[v]>b[u][i]){
        d[v]=b[u][i];
        q.push(ii(-d[v],v));
      }
    }
  } 
    cout<<sum;
}


int main() 
{
  cin>>n>>m;
  int v,c; cin>>v>>c;
  for(i=1;i<=m;i++){
    string s; cin>>s;
    cin>>x>>y>>z;
    if(s=="both"){
        if(c<v){
            z*=c;
        }
        else{
            z*=v;
        }
    }
    if(s=="big") z*=v;
    if(s == "small") z*=c;
    a[x].push_back(y);
    b[x].push_back(z);
    a[y].push_back(x);
    b[y].push_back(z);
  }
prim(1);
    return 0;
}