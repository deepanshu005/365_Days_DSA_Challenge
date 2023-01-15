// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
     // aabbacbccabdacba & abc
public:
	int search(string pat, string txt) {
	    int ans = 0;
	    unordered_map<char,int> m;
	    int pLen = pat.size();
	    int tLen = txt.size();
	    for( int i=0; i<pLen; i++ ){//putting all elements of pattern in map
	        m[pat[i]]++;
	    }
	    int count = m.size();// if we dont use count then at each sliding of window we have to traverse the map is there any required character
	    // But with the use of we can keep this with us 'Do we require any other character'
	    for( int i=0, j=0; j<tLen; j++ ){
	        if( j-i+1<pLen ){// means we dint reached to the window size
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	                count--;
	        }
	        else if( j-i+1==pLen ){// measn window size becomes equal to pattern length
	            m[txt[j]]--;// naye element ka hisaab baraabar krne k liye
	            if(m[txt[j]]==0)
	                count--;
	            
	            if( count==0 )
	               ans++; 
	            
	            if(m[txt[i]]==0)// means i wala humaare kaam ka tha
	                count++;
	            
	            m[txt[i]]++;// as we have to remove element at index i 
	            i++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
