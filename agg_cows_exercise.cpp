#include <iostream>
using namespace std;

// O(2^N) -> n <= 27
int maximize_the_min_distance(int arr[], int n, int k)
{
    int ans = INT_MIN;

    for (int i = 1; i < (1 << n); i++)
    {
        int count = 0;
        int min_dis = INT_MAX;
        int last = -1;
    
        for (int j = 0; j < (1 << n); j++)
        {
            if ((i & (1 << j)) != 0)
            {   
                count++;
                if(last == -1){
                    last = arr[j];
                }
                else{
                    min_dis = min(min_dis, arr[j] - last);
                    last = arr[j];
                }
            }
        }

        if(count == k && min_dis != INT_MAX){
            ans = max(ans, min_dis);
        }
    }
    return ans;
}

// O(n) 
bool isPossible(int arr[], int n, int d, int k){
     int count = 1;
     int last_pos = arr[0];

     for(int i = 1; i < n; i++){
        if(arr[i] - last_pos >= d){
            count++;
            last_pos = arr[i];
        }

        if(count == k){
            return true;
        }
     }
     return false;   
}

// O(n*log2(10^9))
int agg_cows(int arr[], int n, int k){
    int s = 1;
    int e = arr[n - 1] - arr[0];
    int ans = -1;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(isPossible(arr, n, mid, k)){
            s = mid + 1;
            ans = mid;
        }
        else{
            e = mid - 1;
        }
    }


    return ans;
}


int main(){
    int arr[] = {1, 6, 8, 13, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    cout << agg_cows(arr, n, k) << '\n';

    cout << maximize_the_min_distance(arr, n, k) << '\n';
}