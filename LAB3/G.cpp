#include <iostream>
#include <vector>

using namespace std;

int summa(vector <int> v,int mid ){
    int sum = 0;
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] % mid == 0 and v[i] >= mid)sum += v[i]/mid;
        else sum += (v[i]/mid)+1;
    }
    return sum;
}

int main()
{
    vector <int> v;
    int n,f; cin >> n >> f;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int left = 1,right = 9999999;
    int out = right;

    while (left <= right)
    {
        int mid = (right - left)/2 + left; 
        if(summa(v,mid) <= f){
            out = min(out,mid);
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << out;
    
}