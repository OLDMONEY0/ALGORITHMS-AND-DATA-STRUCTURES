#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    int target; cin >> target;

    int left = 0, right = n ;

    bool find = false;
    while (left <= right)
    {
        int mid = (left+right)/2;
        if(arr[mid] > target)right = mid - 1;
        else if(arr[mid] < target)left = mid + 1;
        else{
            cout << "Yes";
            find = true;
            break;
        }
    }

    if(find == false)cout << "No";
    
}