// This is the correct answer
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{
// there will be atmost k candies free if we buy one candy and if we buy 2 candies then atmost (2*k) candies will be free
// In previous approach I thought there will be only k candies are free whether we buy 1 or many candies
public:
    vector<int> candyStore(int candies[], int N, int k){
        sort( candies, candies+N );
        int mini = 0;
        int maxi = 0;
        int i = 0;
        int j = N-1;
        while( i<=j ){//for minimum, we will buy one candy from starting and last k candies will be free and the remaining candies we have to buy forecefully
            mini = mini + candies[i];
            i++;
            j = j-k;
        }
        reverse( candies, candies+N );// just reverses the order of candies
        i = 0;
        j = N-1;
        while( i<=j ){//for maximum, we will buy one candy from ending and starting k candies will be free and the remaining candies we have to buy forecefully
            maxi = maxi + candies[i];
            i++;
            j = j-k;
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
