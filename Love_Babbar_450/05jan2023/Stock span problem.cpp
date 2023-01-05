// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define PII pair<int,int>
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    // Nearest greater in left
    // Simply applying nearest greater in left but this time we are storing  prev greaters' index in vec
    // after storing in vec we will subtract the values in vec with respective indexes
    vector <int> calculateSpan(int price[], int n){
        vector<int> vec;
        stack< PII > st;//  < index, value >
        for( int i=0; i<n; i++ ){
            while( !st.empty() and st.top().second<=price[i] ){
               st.pop();
            }
            if( st.empty() ){
               vec.push_back( -1 );
            }
            else{
                vec.push_back( st.top().first );
            }
            st.push( {i,price[i]} );
       }
       vector<int>ans;
       for( int i=0; i<n; i++ ){
           ans.push_back( i-vec[i] );
       }
       return ans;
    }
};

    /*My appraoch which is wrong
    vector <int> calculateSpan(int price[], int n){
        vector <int> vec;
        stack<int> st;
        vec.push_back(1);
        st.push( price[0] );
        for( int i=1; i<n; i++ ){
            int count = 0;
            if( price[i]>=price[i-1] )
                count+=vec[i-1];
            st.push( price[i] );
            while( !st.empty() and st.top()<=price[i] ){
                st.pop();
                count++;
            }
            vec.push_back(count);
        }
    }

*/

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
