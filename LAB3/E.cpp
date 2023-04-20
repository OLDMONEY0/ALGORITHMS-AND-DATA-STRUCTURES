#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int farm(vector<vector<int>> &v, int x){
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        bool ok = true;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] > x) ok = false;
        }
        if(ok) ans++;
    }
    return ans;
};

int main()
{
    int n,k; cin >> n >> k;
    vector<vector<int>> v;

    for(int i = 0; i < n; i++){
        vector <int> row;
        for(int j = 0 ; j < 4; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }

    int left = 0, right = 1e9+2;

    while (left + 1 < right)
    {
        int mid = (left+right)/2;
        if(farm(v,mid) >= k)right = mid;
        else left = mid; 
    }

    cout << right;
    
}