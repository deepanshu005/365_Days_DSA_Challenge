// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
// Using stack of recursion
    static void insert_at_bottom( stack<int>&st, int i, int x ){
        if( i<=1 )
            st.push(x);

        else{
	        int a = st.top();
            st.pop();
            insert_at_bottom(st, i-1, x);
	//push all the items held in Function Call Stack//once the item is inserted at the bottom
	        st.push(a);
	    }
    }

    void Reverse(stack<int> &st){
        int n = st.size();
        int i = 0;
        while( n ){
            int x = st.top();
            st.pop();
            i = n;
            insert_at_bottom( st, i, x);// i am passing i here such that it would insert at ith above from bottom of stack
            n--;
        }
        return;
    }
};



/* Using stack
    void Reverse(stack<int> &st){
        stack<int> healer;
        int n = st.size();
        int i = 0;
        while( n ){
            int x = st.top();
            st.pop();
            i = n;
            while( i>1 ){
                healer.push(st.top());
                st.pop();
                i--;
            }
            st.push(x);
            while( !healer.empty() ){
                st.push(healer.top());
                healer.pop();
            }
            n--;
        }
        return;
    }
};


// Simply phle stack ko khaali krke queue mein daal do 
// And then empty the queue by pushing elements to the stack again
    void Reverse(stack<int> &st){
        queue<int> q;
        while( !st.empty() ){
            q.push(st.top() );
            st.pop();
        }
        while( !q.empty() ){
            st.push(q.front() );
            q.pop();
        }
        return;
    }*/

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
