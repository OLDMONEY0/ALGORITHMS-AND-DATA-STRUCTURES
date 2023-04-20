#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> d;
    int l; cin>>l;
    int check = 0;
    int cnt = 0;
    int cnt2 = 0;
    for(int i=0; i<l; i++){
        int f; cin>>f;
        if(f == 1){
            int num; cin>> num;
            cnt++;
            if(check%2==0){
                d.push_back(num);
            }
            if(check%2==1){
                d.push_front(num);
            }
        }
        else{
            check++;
            cnt2++;
        }
    }
    
    if(cnt2 % 2 == 1){
        for(int i = 0; i<cnt; i++){
            cout << d.back() << " ";
            d.pop_back();
        }
    }
    else{
        for(int i = 0; i<cnt; i++){
            cout << d.front() << " ";
            d.pop_front();
        }
    }
}