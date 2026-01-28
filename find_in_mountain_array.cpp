#include<iostream>
using namespace std;

int peakElement(int arr[], int n){
        int s = 1;
        int e = n - 1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return arr[mid];
            }

            if(arr[mid] < arr[mid + 1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return -1;
}

int binary_search_inc(int arr[], int l, int r, int target){
    
    while(l <= r){
        int mid = l + (r - l) / 2;
       
        if(arr[mid] == target){
            return mid;
        }
        
        if(arr[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return -1;
}

int binary_search_dec(int arr[], int l, int r, int target){
    
    while(l <= r){
        int mid = l + (r - l) / 2;
        

        if(arr[mid] == target){
            return mid;
        }
        
        if(arr[mid] < target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;
    
    int peakIndex = peakElement(arr, n);
    int isPresentInLeft = binary_search_inc(arr, 0, peakIndex, target);
    if(isPresentInLeft != -1){
        cout << isPresentInLeft;
        return 0;
    }
    int isPresentInright = binary_search_dec(arr, peakIndex + 1, n - 1, target);

    cout << isPresentInright;

}