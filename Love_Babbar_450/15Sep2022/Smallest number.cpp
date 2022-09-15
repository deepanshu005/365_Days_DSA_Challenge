//CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        int arr[D] = {0};
        int i = 0;
        arr[0] = 1;
        S--;
        string str = "";
        for( i=D-1; i>0; i-- ){
            if( S>9 ){//
                arr[i] = 9;
                S = S-9;
            }
            else{
                arr[i] = S;
                S = 0;
                break;
            }
        }
        if( i==0 and S>0 and S<9 ){
            arr[i] = S+1;
            S = 0;
        }
        if( S>0 )// if whole array is traversed but still S is greater than 0 means there doesnt exist such  number hence we are returning "-1" 
            return "-1";
        for( auto x : arr ){//Copying the whole array to the string str
            str += to_string(x);
        }
        return str;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
