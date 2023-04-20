#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > g;
int cnt = 0;


int main() {
	int n; cin >> n;
	g = vector<vector<int> >(n);
	vector<int> d(n);

	for(int i = 0; i < n; i++) {
			d[i] = -1;
			for(int j = 0; j < n; j++) {
				int a; cin >> a;
				g[i].push_back(a);
			}
	}

	int start, end;
	cin >> start >> end;
	start--;end--;
	queue<int> q;
	q.push(start);
	d[start] = 0;

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int to = 0; to < n; to++) {
			if(g[v][to] == 1 && d[to]==-1) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}

	cout << d[end];

	return 0;
}