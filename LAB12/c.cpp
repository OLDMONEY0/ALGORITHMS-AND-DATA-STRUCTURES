#include <bits/stdc++.h>
using namespace std; 
int n;
const int maxn = 655;
vector <int> rw[maxn]; 
vector <int> aw[maxn]; 
int a[maxn][maxn]; 
void solution(vector <bool> u,vector <bool> u1,vector <int> d,vector <int> d1){
    if (!u[n-1] || !u1[n-1]){ 
        cout << -1; 
    } else { 
        cout << max(d[n-1], d1[n-1]); 
    } 
}

int main(){ 
    int m; 
    cin >> n >> m; 
    queue <int> q; 
    queue <int> q1;
    n++; 
    vector <int> d(n); 
    vector <int> d1(n); 
    vector <bool> u(n);
    vector <bool> u1(n);
    n--; 
    for(int i = 0; i < m; i++){ 
        int x, y; 
        cin >> x >> y; 
        x -= 1; y -= 1; 
        rw[x].push_back(y); 
        rw[y].push_back(x); 
        a[x][y] = 1; 
        a[y][x] = 1; 
    } 

    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (a[i][j] == 0 && i != j){ 
                aw[i].push_back(j); 
            } 
        } 
    } 
 
    q.push(0); 
    u[0] = true; 
    while(!q.empty()){ 
        int v = q.front(); 
        q.pop(); 
        for(int i = 0; i < rw[v].size(); i++){ 
            int to = rw[v][i]; 
            if(!u[to]){ 
                u[to] = true; 
                q.push(to); 
                d[to] = d[v]+1; 
            } 
        } 
    } 

    q1.push(0); 
    u1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < aw[v].size(); i++){ 
            int to = aw[v][i]; 
            if(!u1[to]){ 
                u1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v] + 1; 
            } 
        } 
    } 
    solution(u,u1,d,d1);
}