#include<bits/stdc++.h>

using namespace std;


int main(){
    int n; cin>>n;                //m.insert({name, nick});
    map<string, string> m;
    for(int i=0; i<n; i++){
        string name, nick ; cin>>name>>nick;
        
        if(!m.empty()){
            int cnt=0;
            for(auto j=m.begin(); j!=m.end(); j++){
                if(j->second == name){
                    j->second = nick;
                    cnt++;
                }
            }
            if(cnt<1){
                m.insert({name, nick});
            }
            
        }
        else{
            m.insert({name, nick});
        }
    }
    cout << m.size()<<endl;
    for(auto i=m.begin(); i!=m.end(); i++){
        cout << i->first << " " << i->second<< endl;
    }
}