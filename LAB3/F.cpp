#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int binary_search(vector <int> v, int n, int tar){
	int left = 0, right = n - 1, mid, index = -1;
	while(left <= right){
		mid = (left + right) / 2;
		if(tar < v[mid]){
			index = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return index;
};

int summa(vector <int> v, int pos){
	int sum = 0;
	for(int i = 0; i < pos; i++) sum += v[i];
	return sum;
};

int main(){
	int n; cin >> n;
	vector <int> v;
	for(int i=0; i<n; i++){
        int x;cin >> x; 
        v.push_back(x);
    }
	sort(v.begin(), v.end());
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int x; cin >> x;
		if(x < v[0]){
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		if(x >= v[n-1]){
			cout << n << ' ' << summa(v, n) << '\n';
			continue;
		}
		int pos = binary_search(v, n, x);
		int sum = summa(v, pos);
		cout << pos << ' ' << sum << '\n';
	} 
}