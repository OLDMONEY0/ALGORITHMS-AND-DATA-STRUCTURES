#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> p;
    int n,m, zap; cin >> n >> m;
    vector <int> v;
    int s = 0;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        s += x;
        v.push_back(s);
    }
    int out = 0;
    for(int i = 0 ; i < m; i++){
        int x; cin >> x;
        if(x <= v[0]){
            out = 1; 
        }
        else{
            int left = 0,right = n - 1;
            while (left <= right)
            {
                int mid = (right + left)/2;

                if(x > v[mid] and x <= v[mid+1]){
                    out = mid + 2;
                    break;
                }
                else if(x <= v[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        
        cout << out << endl;

    }
}