// CPP DSA Love Babbar 450
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> vec;
        vec.push_back(1);
        for( int i=2; i<=N; i++ ){
            int carry = 0;
            int num = 0;
            for( int j=0; j<vec.size(); j++ ){
                num = vec[j]*i + carry;
                vec[j] = num%10;
                carry = num/10;
            }
            while( carry ){// for carry greater than equal to 10 and j has reached to the end of vector
                num = carry%10;
                vec.push_back(num);
                carry = carry/10;
            }
            // if( carry )
                // vec.push_back(carry);
        }
        
        reverse( vec.begin(), vec.end());
        return vec;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
