#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long oshiete(vector<long long> &v, long long num){
    long long sum = 0, ans = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > num) return __INT_MAX__;
        if(sum + v[i] > num){
            ans++;
            sum = v[i];
        }
        else sum += v[i];
    }
    if(sum) ans++;
    return ans;
}
int main(){
    int n, k; cin >> n >> k;
    vector<long long> v(n);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    } 
    long long left = 0, right = 1e18+123;
    while(left  + 1 < right){
        long long mid = (left + right)/2;
        long long num = oshiete(v, mid);
        if(num > k) left = mid;
        else right = mid;
    }     
    cout << right;
}