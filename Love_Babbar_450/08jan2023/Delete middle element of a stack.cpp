// CPP DSA Love Babbar 450
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    //Stack = {1, 2, 3, 4, 5}
    // point to note is 5 is the top of stack
    // heance find mid carefully
    void deleteMid(stack<int>&st, int sizeOfStack){
        int mid = (st.size())/2;
        int count = 1;
        // std::cout<<st.top()<<endl;
        stack<int> healer;
        while( count<=mid ){
            healer.push(st.top());
            st.pop();
            count++;
        }
        st.pop();
        while( !healer.empty() ){
            st.push(healer.top());
            healer.pop();
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
