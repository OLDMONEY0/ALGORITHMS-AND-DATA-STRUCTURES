#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> g[N];
int visited[N];
vector<int> vm;
bool ok = false;
void dfs(int v){

	visited[v] = 1;
	for(int i : g[v]){
		if(visited[i] == 1){
			ok = 1;
		}
		if(!visited[i]){
			dfs(i);
		}
	}
	visited[v] = 2;
	vm.push_back(v);

}

int main(){
	int n,m;cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y;cin >> x >> y;
		g[x].push_back(y);		
	}

	for(int i = 1; i <= n; i++){
		if(visited[i]==0){
			dfs(i);
		}
	}

	if(ok){
		cout << "Impossible";
		return 0;
        
	}
	cout << "Possible\n";
	for(int i = vm.size()-1; i >= 0; i--){
		cout << vm[i] << " ";
	}

	
}