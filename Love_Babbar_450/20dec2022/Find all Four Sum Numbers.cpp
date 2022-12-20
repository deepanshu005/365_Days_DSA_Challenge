// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
   vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());   //sort the array
        vector<vector<int>> res;
         
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                int low=j+1;
                int high=n-1;
                long long sum=target-(long long)arr[i]-(long long)arr[j];
                while(low<high){
                    if((long long)arr[low]+(long long)arr[high]==sum){
                        vector<int> vec;
                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[low]);
                        vec.push_back(arr[high]);
                        res.push_back(vec);
                        while(low<high && arr[low]==arr[low+1])        //skip duplicates
                            low++;
                        while(low<high && arr[high]==arr[high-1])      //skip duplicates
                            high--;
                            
                        low++;
                        high--;
                    }
                    else{
                        if((long long)arr[low]+(long long)arr[high]<sum)
                            low++;
                        else
                            high--;
                    }
                }
                while(j<n-3 && arr[j]==arr[j+1])  //skip duplicates
                    j++;
            }
            while(i<n-4 && arr[i]==arr[i+1])      //skip duplicates
                i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
