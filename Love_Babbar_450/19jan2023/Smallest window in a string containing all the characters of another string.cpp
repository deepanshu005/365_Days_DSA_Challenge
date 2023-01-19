// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        unordered_map<char, int> mp;
        int i=0;
        int j=0;
        int sLen = s.size();
        int pLen = p.size();
        pair<int, int> ans = {-1,-1};
        while( i<pLen ){// Simply traversing the pattern and assigning to map
            mp[p[i]]++;
            i++;
        }
        int count = mp.size();// Counts the number of distinct element required
        i = 0;
        while( j<sLen ){
            if( mp.find(s[j]) != mp.end() ){// if jth element present in map
                mp[s[j]]--;
                if( mp[s[j]]==0 ){
                    count--;// qunki jth element ki requirement puri hui
                }
            }
            while( count==0 ){// Simply trying to shrink the window
                if( mp.find(s[i]) != mp.end() ){// if arr[i] is present in map
                    mp[s[i]]++;// s[i] is present in map heance uski jaane se humme fark padega
                    if( mp[s[i]] > 0 ){
                        count++;
                    }
                    if( count>0 ){
                        if( ans.first == -1 ){// when first correct window hits
                            ans.first = i;
                            ans.second = j;
                        }
                        else if( (ans.second) - (ans.first) > j-i ){// if lesser sized window is present
                            ans.first = i;
                            ans.second = j;
                        }
                    }
                }
                i++;
            }
            j++;
        }
        if( ans.first==-1 ){// no valid window is present 
            return "-1";
        }
        int a = ans.first;
        int b = (ans.second) - (ans.first)+1;
        return s.substr( a,b );
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
