#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100000];
    int length;
    public:
        Heap(){
            a[0] = INT_MAX;
            length = 0;
        }


        int shift_up(int i){
            while(i > 1 && a[i/2] < a[i]){
                swap(a[i], a[i/2]);
                i = i/2;
            }
            return i;
        }
        
        
        void insert(int val){
            length++;
            a[length] = val;
            shift_up(length);
        }

        int count(){
            int cnt = 0;
            for (int i=1; i<=length; i++){
                int left = 2*i;
                int right = 2*i+1;
                if(left>=length) break;
                if(a[right] > a[left]) cnt++;

            }
            return cnt;
        }
};

int main(){
    int n; cin>>n;
    Heap h;
    for (int i=0; i<n; i++){
        int mem; cin>>mem;
        h.insert(mem);
    }
    cout << h.count();
    return 0;
}