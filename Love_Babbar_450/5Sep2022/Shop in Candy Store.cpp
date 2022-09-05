// Result is not correct because I thought there will be only k free candies after buying one or more candies
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k){
        sort( candies, candies+N );
        int mini = candies[0];
        int maxi = candies[N-1];
        if( k < N-1 ){ // if k would be greater than or equal to (N-1) then we will be buying only one candy and other will be free
            int i = 1;
            while( i<N-k ){//for minimum, we will buy one candy from starting and last k candies will be free and the remaining candies we have to buy forecefully
                mini = mini + candies[i];
                i++;
            }
            i = N-2;
            while( i>=k ){//for maximum, we will buy one candy from ending and starting k candies will be free and the remaining candies we have to buy forecefully
                maxi = maxi + candies[i];
                i--;
            }
        }
        return { mini, maxi };
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
