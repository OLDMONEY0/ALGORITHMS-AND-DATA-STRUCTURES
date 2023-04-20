#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<vector<int> > G;
vector<int> parent;
int found_g (int v) {
	if (v == parent[v]) {
		return v;
	} 
    else{
        parent[v] = found_g(parent[v]);
		return parent[v];
	}
}

int DSU_U (int a, int b) {
	a = found_g (a);
	b = found_g (b);
	if (rand() & 1) 
        swap (a, b);
	if (a != b){
		parent[a] = b;
        return 1;
    }
    return 0;
}

int main(){
    int x, y; 
    cin >> x >> y;
    parent.resize(x);
    G.resize(x);
    for(int i=0; i<y; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=0; i<x; i++){
        parent[i] = i;
    }
    
    int cnt = 0;
    vector<int> san;
    for(int i = x-1; i >=0; i--) {
        san.push_back(cnt);
        for(int j=0; j<G[i].size(); j++){
            if(G[i][j] > i && DSU_U(i, G[i][j]) == 1) cnt--;
        }
        cnt++;
    }

    for(int i=san.size()-1; i>=0; i--){
        cout << san[i] << endl;
    }
}