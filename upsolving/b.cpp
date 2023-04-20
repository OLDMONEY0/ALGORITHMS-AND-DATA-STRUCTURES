#include<iostream>
#include<cmath>

using namespace std;

int bool_is_prime(int n){
    for(int i=2; i<int(sqrt(n))+1; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n; cin>>n;
    for(int i=2; i<n; i++){
        if(bool_is_prime(i)){
            int b = n - i;
            if(bool_is_prime(b)){
                cout << i << " " << b;
                break;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
        
    }
}