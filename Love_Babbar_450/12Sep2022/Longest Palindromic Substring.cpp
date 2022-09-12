// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        bool isPallin(string str){//Simple code to check if a string is a palindroem or not
            int s=0;
            int e = str.length()-1;
            while(s<e){//Just two pointer approach to check if the string is palindrome or not
                if(str[s]!=str[e])
                    return false;
                s++;
                e--;
            }
            return true;
        }
    public:
        string longestPalin (string str) {
            int len = 0;//to store the maximum palindromic length till now
            int index;//to trace at which index we got the max palindromic length
            int n = str.length();
            for ( int i = 0; i<n; i++ ){
                string subStr;
                for (int j = i; j <n; j++) {
                    subStr += str[j];
                    if(isPallin(subStr)){
                        if(subStr.length()>len){
                            len = subStr.length();
                            index = i;
                        } 
                    }
                }
                if( n-i <= len )//if we din't write this check condition, our code will work fine
                    break;//but to avoid unneccessary traversal we put this check
            }
            return str.substr(index,len);
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
