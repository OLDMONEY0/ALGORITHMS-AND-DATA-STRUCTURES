#include <bits/stdc++.h>
using namespace std; 

const int INF = 1000000000;
vector<pair<int,int>> g[200008]; 
vector<int> d(200008, INF); 
int n,m; 

int fs(int l, int end){ 
    d.clear(); 
    for(int i = 0; i < 200009; i++){ 
        d[i] = INF; 
    } 
    d[l] = 0; 
    set <pair<int,int> > q; 
    q.insert(make_pair(d[l],l)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
                q.erase(make_pair(d[to], to)); 
                d[to] = d[v] + len; 
                q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 



int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int u,v,c; 
        cin >> u >> v >> c; 
        g[u].push_back({v,c}); 
        g[v].push_back({u,c}); 
    } 
    int s, a, b, f; 
    cin >> s >> a >> b >> f; 
    int x, y; 
    x = fs(s, a) + fs(a,b) + fs(b,f); 
    y = fs(s, b) + fs(b,a) + fs(a,f) ; 
    if(min(x, y) <= INF) cout << min(x, y);
    else cout << -1; 
    return 0; 
}