// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        stack<char> st;
        for( auto it : x ){
            if( it=='{' or it=='(' or it=='['  )
                st.push(it);
            else if( !st.empty() ){
                if( it==')' and st.top() == '(' )
                    st.pop();
                else if( it==']' and st.top() == '[' )
                    st.pop();
                else if( it=='}' and st.top() == '{' )
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
