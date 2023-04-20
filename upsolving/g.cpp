#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> d;
    int n; cin>> n;
    for (int i=0; i<n; i++){
        int mem; cin>>mem;
        if (mem > 3000){
            d.push_back(mem);
            while(d.size() != 0 && d.front() < mem - 3000){
                d.pop_front();
            }
            //if (d.front() >= mem - 3000){
            //    d.pop_front(d.front());
           // }
        }
        else{
            d.push_back(mem);
        }
            
        cout << d.size() << " ";
    }
}