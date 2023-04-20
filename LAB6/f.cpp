#include <bits/stdc++.h>
#define ll long long
using namespace std;



const int N=1e5;
int t;
pair<pair<string, string>, float> arr[N];

struct node{
    string nick;
    string firstname;
    double grade;
};


void heapup(int a){
    while(a>1 && arr[a].second <= arr[a/2].second){
        swap(arr[a], arr[a/2]);
        a =a/2;
    }
    while(a>1 && arr[a].second == arr[a/2].second){
        if(a>1 && arr[a].first.second < arr[a/2].first.second){
            swap(arr[a], arr[a/2]);
            a =a/2;
            continue;
        }
        break;

    }
    while(a>1 && arr[a].first.second == arr[a/2].first.second && arr[a].second == arr[a/2].second){
            if(a>1 && arr[a].first.first < arr[a/2].first.first){
                swap(arr[a], arr[a/2]);
                a =a/2;
                continue;
            }
            break;
        }

}

void add1(pair<pair<string, string>, float> x){
    arr[++t] = x;
    heapup(t);
}

void heapdn(int v){
    int dp=v; 
    if(v*2 <= t && arr[dp].second > arr[v*2].second){
    if(v*2 <= t && arr[dp].second > arr[v*2].second) dp = dp*2;
    if(v*2+1 <= t && arr[dp].second > arr[v*2+1].second) dp = dp*2+1; 
    } else if(v*2 <= t && arr[dp].second == arr[v*2].second && arr[dp].first.second > arr[v*2].first.second){
    if(v*2 <= t && arr[dp].second == arr[v*2].second && arr[dp].first.second > arr[v*2].first.second) dp = dp*2;
    if(v*2+1 <= t && arr[dp].second == arr[v*2+1].second && arr[dp].first.second > arr[v*2+1].first.second) dp = dp*2+1;
    } else {
    if(v*2 <= t && arr[dp].second == arr[v*2].second && arr[dp].first.second == arr[v*2].first.second && arr[dp].first.first > arr[v*2].first.first) dp = dp*2;
    if(v*2+1 <= t && arr[dp].second == arr[v*2+1].second && arr[dp].first.second == arr[v*2+1].first.second && arr[dp].first.first > arr[v*2+1].first.first) dp = dp*2+1;
    }   
    if(dp != v){
        swap(arr[dp], arr[v]);
        heapdn(dp);
    }
}

pair<pair<string, string>, float> pop_top(){
    pair<pair<string, string>, float> top = arr[1];
    swap(arr[1], arr[t--]);
    heapdn(1);
    return top;
}

bool comp(node a, node b){
    if(a.grade == b.grade){
        if(a.nick == b.nick){
            return a.firstname > b.firstname;
        }
        else return a.nick > b.nick;
    }
    return a.grade > b.grade;

}

int partition(vector<node> &a,int low,int mid, int high){
    vector<node> cur;
    int j = mid + 1;
    int i = low;
    int k = low;


    while(i<= mid && j <= high){
        if(!comp(a[i], a[j])){
            cur.push_back(a[i]);
            ++i;
        } else {
            cur.push_back(a[j]);
            ++j;
        }
    }
    while(i<=mid){
        cur.push_back(a[i]);
        ++i;
    }
    while(j<=high){
        cur.push_back(a[j]);
        ++j;
    }
    for(int i=low; i<=high; i++){
        a[i] = cur[i-low]; 
    }
}


void merge_sort(vector<node> &a, int low, int high){
    if(low<high){
        int mid = (low+high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        partition(a, low, mid, high );

    }
}


int main(){
    int n; cin>>n;
    vector<node> a(n);
    for(auto &cur : a){
        cin >> cur.nick >> cur.firstname;
        int x; cin >> x;
        double cnt = 0, cnt1 = 0;
        double gpa;
        for(int j=0; j<x; j++){
                string grade;
                cin>>grade;
                if(grade == "A+"){
                    gpa = 4.00;
                }
                if(grade == "A"){
                    gpa = 3.75;
                }
                if(grade == "B+"){
                    gpa = 3.50;
                }
                if(grade == "B"){
                    gpa = 3.00;
                }
                if(grade == "C+"){
                    gpa = 2.50;
                }
                if(grade == "C"){
                    gpa = 2.00;
                }
                if(grade == "D+"){
                    gpa = 1.50;
                }
                if(grade == "D"){
                    gpa = 1.00;
                }
                if(grade == "F"){
                    gpa = 0;
                }
                int numbe;
                cin >> numbe;
                cnt+=(numbe*gpa); cnt1+=numbe;
        }
        cur.grade = cnt / cnt1;
    }
    merge_sort(a,0, n-1);
    for(auto &cur : a){
        cout << cur.nick << " " << cur.firstname << " " << fixed << setprecision(3) << cur.grade << endl;
    }


    return 0;
}