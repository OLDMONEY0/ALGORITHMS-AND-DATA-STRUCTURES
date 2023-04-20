#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[200001];
pair<int, pair<int, int> > conn[200001];
long ans = 0;

int find_set(int v)
{   
    if(v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

int union_set(int u, int v, int c)
{   
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        p[u] = v;
        ans += c;
    }
    return v;
}

int main(){
    int n, m, c;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {                       
        int l, r, c; 
        cin >> l >> r >> c;
        conn[i] = make_pair(c, make_pair(--l, --r));
    }

    for(int i=0; i<n; i++)
    {
        p[i] = i;
    }
    sort(conn, conn + m);

    for(int i=0; i<m; i++)
    {                                   
        int l = conn[i].second.first;
        int r = conn[i].second.second;
        c = conn[i].first;
        for(int j=l+1; j<=r; j++)
        {
            j = union_set(l, j, c);
            if(j > r){
                break;
            }
        }
    }
    cout << ans;

    return 0;
}