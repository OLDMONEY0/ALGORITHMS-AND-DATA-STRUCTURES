
#include <bits/stdc++.h>

using namespace std;
int main()
{
    stack <int> s, s2;
    int n; cin>>n;
    int max = 0;
    for(int i=0; i<n; i++){
        string str; cin>>str;
        if(str == "add"){
            int mem ; cin>>mem;
            if( mem > max) max = mem;
            s.push(mem);
        }
        if(str == "delete") {
            if (s.top() != max){
                s.pop();
            }
            else{
                max = 0;
                s.pop();
                while(!s.empty()){
                    s2.push(s.top());
                    if(s.top() > max) max = s.top();
                    s.pop();
                }
                while(!s2.empty()){
                    s.push(s2.top());
                    s2.pop();
                }
            }
        }
        if(str == "getmax"){
            if(s.size() == 0) cout << "error" << endl;
            else {
                cout << max << endl;
            }
        }
        if(str == "getcur"){
            if (s.size() == 0) cout << "error" <<  endl;
            else{
                cout << s.top() << endl;
            }
        }
        
    }
}