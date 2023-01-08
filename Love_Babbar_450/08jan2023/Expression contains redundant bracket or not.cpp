// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // Aproach is simple do closing brackets k ander el perator hona jaruri h
    int checkRedundancy( string str ){
        stack<char> st;
        int n = str.size();
        for( int i=0; i<n; i++ ){
            if( str[i]=='(' or str[i]=='*' or str[i]=='/' or str[i]=='+' or str[i]=='-' ){
                st.push( str[i] );//stack will only contain opertators and (
            }
            else if( str[i]==')' ){// whenever we encounter ) we will check if there is any operator in between ( and )
                if( st.top() == '(' )// if no operator in between we will return redundancy
                    return 1;
                while( st.top()!= '(' )// otherwise we will remove all operators and ( for one parenthesis of type )
                    st.pop();
                st.pop();
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
