#include <bits/stdc++.h>

using namespace std;

int minute = 0;
queue<pair<int, int>> mar_pos; 
bool one = false;

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 1 && !one)
                one = true;
        }
    }
}

void step(vector<vector<int>> &v, int r, int c, int n, int m){
    if(r < n  && c < m && r >= 0 && c >=0 && v[r][c] == 1){
        v[r][c] = 2;
        mar_pos.push(make_pair(r, c));
    }   
}

void bfs(vector<vector<int>> &v, int n, int m) {
    int encnt = mar_pos.size();
    while (!mar_pos.empty()) {
        if (encnt == 0) {
            minute++;
            encnt = mar_pos.size();
        }
        pair<int, int> mar = mar_pos.front();
        mar_pos.pop();
        encnt--;
        step(v, mar.first + 1, mar.second, n, m);
        step(v, mar.first, mar.second + 1, n, m);
        step(v, mar.first - 1, mar.second, n, m);
        step(v, mar.first, mar.second - 1, n, m);
    }      
}

int main() {
    int n, m;
    cin >> n >> m;
    bool two = false;
    vector<vector<int>> v(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2)
                mar_pos.push(make_pair(i, j));
            
            if (!two && v[i][j] == 1)
                two = true;
        }
    if (!two) {
        cout << minute;
        return 0;
    }
    bfs(v, n, m);
    print(v);
    if (!one)
        cout << minute;
    else 
        cout << -1; 

    return 0;    
} 