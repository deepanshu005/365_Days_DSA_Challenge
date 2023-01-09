// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    // Naive Aproach is using two nested loops and inner loop depends on outter loop which gives idea to use stack here 
    // But we cant use exrta space in this question moreover idk the stack approach  😂😂
    int tour(petrolPump p[],int n){
        int start = 0;
        int reqFuel = 0;
        int extFuel = 0;
        for( int i=0; i<n; i++ ){
            extFuel += (p[i].petrol - p[i].distance);
            if( extFuel<0 ){
                reqFuel += extFuel;
                extFuel = 0;
                start = i+1;
            }
        }
        if( reqFuel+extFuel >= 0 )
            return start;
        
        return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
