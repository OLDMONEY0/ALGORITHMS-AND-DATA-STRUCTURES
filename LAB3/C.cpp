#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,q; cin >> n >> q;
    vector <int> v;
    for(int i = 0 ; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < q; i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for(int i = 0 ; i < v.size(); i++){
            if(l1 <= v[i] and v[i] <= r1){
                cnt++;
            }
            else {
                if(l2 <= v[i] and v[i] <= r2)cnt++;
            }
        }

        cout << cnt << endl;
    }  
}