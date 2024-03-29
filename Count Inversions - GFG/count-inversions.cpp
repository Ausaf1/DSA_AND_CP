//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long low,long long mid,long long high){
        vector<long long> temp;
        long long left = low,right = mid + 1;
        long long int cnt = 0;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += mid - left + 1;
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low;i <= high;i++) arr[i] = temp[i - low];
        return cnt;
    }
    long long int mergeSort(long long arr[],long long low,long long high){
        long long int cnt = 0;
        if(low < high){
            long long int mid = (low + high) >> 1;
            cnt += mergeSort(arr,low,mid);
            cnt += mergeSort(arr,mid + 1,high);
            cnt += merge(arr,low,mid,high);
            return cnt;
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends