#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> g[N];
int visited[N];
int dis[N];
int w[N];

void BFS(int v){
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	dis[v] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : g[u]){
			if(!visited[i]){
				visited[i] = 1;
				q.push(i);
				dis[i] = u;
				w[dis[i]]++;
			}
		}
	}
}

int main(){
    int cnt=0;
	int n,m;cin >> n >> m;
	for(int i = 0; i < m; i++){
		int from,to;cin >> from >> to;
		g[from].push_back(to);
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			BFS(i);
			cnt++;
		}
	}
	for(int i = 1; i <= n; i++){
		int to = dis[i];
		if(w[to] < w[i] and to != -1)cnt++;
	}
	cout << cnt;
}