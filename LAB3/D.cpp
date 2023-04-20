#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, bool ok, int x, int l, int r){
    int mid = l + ((r - l)/2);
    if(ok){
        if(l > r) return 0;
        if(x <= v[mid]){
            if(mid == 0) return -1;
            if(v[mid-1] < x) return mid- 1;
            return binary_search(v, true, x, l, mid - 1);
        }
        else{
            if(x <= v[mid+1]) return mid;
            return binary_search(v, true, x, mid + 1, r);
        }
    }
    else{
        if(x >= v[mid]){
            if(mid == v.size()-1) return v.size(); 
            if(x < v[mid+1]) return mid + 1;
            return binary_search(v, false, x, mid + 1, r);
        }
        else{
            if(x > v[mid-1]) return mid;
            return binary_search(v, false, x, l, mid - 1);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector <int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    };

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int sum = 0;
        
        sum += binary_search(v, false, r1, 0, v.size()-1) - binary_search(v, true, l1, 0, v.size()-1) - 1;
        sum += binary_search(v, false, r2, 0, v.size()-1) - binary_search(v, true, l2, 0, v.size()-1) - 1;
        
        int mx = max(l1, l2);
        int mn = min(r1, r2);
        if(mx < mn) sum -= (binary_search(v, false, mn, 0, v.size()-1) - binary_search(v, true, mx, 0, v.size()-1) - 1);
        
        cout << sum << endl;
    }
}