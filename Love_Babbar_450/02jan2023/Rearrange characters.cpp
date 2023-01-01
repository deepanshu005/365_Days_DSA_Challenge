// CPP DSA LOve Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    bool static cmp( pair<int, char> a, pair<int, char> b){
        return a.first<b.first;
    }
    string rearrangeString(string str){
        int n = str.size();
        unordered_map<char, int> m;
        for( auto it : str ){
            m[it]++;
        }
        vector< pair<int, char>> vec;
        for( auto it: m ){
            vec.push_back( {it.second, it.first});
        }
        sort( vec.rbegin(), vec.rend());// to sort a vector of pairs we use r prefix in front of iterator
        
        if( vec[0].first>(n+1)/2 ){
            return "-1";
        }
        int j=0;
        for( int i=0; i<n; i+=2 ){// for even positions
            
            if( vec[j].first>0 ){
                str[i] = vec[j].second;    
                // std::cout<<i<<" "<<vec[j].second<<endl;
                vec[j].first--;
            }
            else{
                i-=2;
                j++;
            }
            
        }
        for( int i=1;i<n; i+=2 ){// for odd positions 
            if( vec[j].first>0 ){
                str[i] = vec[j].second;    
                vec[j].first--;
            }
            else{
                i-=2;
                j++;
            }
        }
        // std:cout<<str<<endl;
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
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends
