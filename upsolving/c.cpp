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

        void update(int p, int k){
            a[p] += k;
            cout << shift_up(p) << '\n';
        }

        void p(){
            for(int i=1; i<=length; i++){
                cout << a[i] << " ";
            }
        }
};

int main(){

    int n; cin>>n;
    Heap h;
    for(int i=0; i<n; i++){
        int mem; cin>>mem;
        h.insert(mem);
    }

    int x; cin>>x;
    for (int i=0; i<x; i++){
        int p; cin>>p;
        int k; cin>>k;
        h.update(p,k);
    }

    h.p();

}