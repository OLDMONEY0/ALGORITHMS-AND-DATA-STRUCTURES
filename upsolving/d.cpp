
#include <iostream>

using namespace std;

int is_prime(int n){
    int last_prime = 0;
    int cnt = 0;
    int divide = 2;
    while(n>1) {
        if(n%divide != 0) {
            divide++;
        }
        else{
            if(last_prime!=divide){
                cnt++;
            }
            last_prime = divide;
            n = n/divide;
        }
    }
    return cnt;
}

int main()
{
    int n; cin>>n;
    cout<<is_prime(n);
}