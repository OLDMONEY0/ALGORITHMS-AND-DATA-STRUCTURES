#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<bool, int> binary_search(vector<int> v, int index, int tar, int left, int right){
    if(left > right) return {false, -1};
    int mid = (left + right)/2;
    if(v[mid] == tar) return {true, mid};
    else if(tar < v[mid]){
        return (index % 2 == 0) ? binary_search(v, index, tar, mid+1, right) : binary_search(v, index, tar, left, mid-1);
    }
    else {
        return (index % 2 == 0) ? binary_search(v, index, tar, left, mid-1) : binary_search(v, index, tar, mid+1, right);
    }
}

pair<int, int> result(vector<vector<int>> &v, int tar){
    int left = 0, right = v.size()-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(mid % 2 == 0){
            if(tar <= v[mid][0] && tar >= v[mid][v[mid].size()-1]){
                pair<bool, int> p = binary_search(v[mid], mid, tar, 0, v[mid].size()-1);
                if(p.first) return {mid, p.second};
                return {-1, -1};
            }
            else if(tar < v[mid][v[mid].size()-1]) left = mid + 1;
            else if(tar > v[mid][0]) right = mid - 1;
        }

        else{
            if(tar <= v[mid][v[mid].size()-1] && tar >= v[mid][0]){
                pair<bool, int> p = binary_search(v[mid], mid, tar, 0, v[mid].size()-1);
                if(p.first) return {mid, p.second};
                return {-1, -1};
            }
            else if(tar < v[mid][0]) left = mid + 1;
            else if(tar > v[mid][v[mid].size()-1]) right = mid - 1;
        }
    }
    return {-1, -1};
}

int main(){
    int t; cin >> t;
    int a[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int n, m; cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    for(int i = 0; i < t; i++){
        if(result(v, a[i]).first == -1) cout << -1 << "\n";
        else cout << result(v, a[i]).first << " " << result(v, a[i]).second << "\n";
    }    
}