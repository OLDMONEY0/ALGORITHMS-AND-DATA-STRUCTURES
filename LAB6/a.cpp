#include<bits/stdc++.h>

using namespace std;

int partition(vector <int> &vec, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j=low; j<high; j++){
        if(vec[j] < vec[pivot]){
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[pivot]);

    return i+1;
}

void qsort(vector <int> &vec, int low, int high){
    if(low < high){
        int pivot = partition(vec, low, high);
    
        qsort(vec, low, pivot - 1);
        qsort(vec, pivot+1, high);
    }
}

int toint(char a){
    int num = a - 0;
    return num;
}

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int>v1;
    vector<int>v2;
    string sum = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'||s[i] == 'o' || s[i] == 'u'){
            v1.push_back(toint(s[i]));
        }
        else{
            v2.push_back(toint(s[i]));
        }
    }
    qsort(v1, 0, v1.size() - 1);
    qsort(v2, 0, v2.size() - 1);
    
    for(int i=0; i<v1.size(); i++){
        sum+=char(v1[i]);
    }
    for(int i=0; i<v2.size(); i++){
        sum+=char(v2[i]);
    }
    
    cout << sum;
}