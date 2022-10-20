//This code is not running completely fine but passed sample test cases
/*
MemeBoy has N balloons with a number written on each. Balloons are represented by a array arr[] where arr[i] denotes the number written on ith balloon. MemeBoy wants to impress MemeGirl using these balloons. MemeGirl loves number X and Y. In order to impress her, MemeBoy can gift a continuous subArray which satisfy. minimum number written in selected sub-array = min(X,Y) maximum number written in selected sub-array = max(X,Y)

Help MemeBoy in selecting the maximum number of balloons that he can gift her. NOTE: Sub-Array is continuous segment of array For e.g. sub-array of [1,3, 4] are [1], [3], [4], [1, 3], [3, 4], [1, 3, 4]

Input Format

First Line will contain integer 'T' denoting number of TestCases
Each of the 'T' testCase will contain 3 lines
First line of each testCase will contain an integer 'N' denoting the total number of balloons
Second Line of each testCase will contain 'N' space-separated integer "Arr[1], Arr[2]...Arr[n]" denoting the number written on the ith Balloon.
Third line will contain 2 integers 'X' and 'Y' denoting the numbers which MemeGirl like
Constraints

1 <= T < 1000 2 <= N <= 1e5 0 <= Arr[i] <= 1e9 Sum of N over all testCases will not exceed 1e5

Output Format

For each test case, output a number on new line denoting the maximum number of balloons that MemeBoy can gift to MemeGirl.
  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t>0){
        int N;
        cin>>N;
        vector<int> vec(N+1,0);
        int k;
        for( int i=1; i<=N; i++ ){
            cin>>k;
            vec[i] = k;
        }
        int X, Y;
        cin>>X>>Y;
        
        int i=1;
        int j = vec.size()-1;
        int left = j;
        int right = 1;
        while( i<j ){
            if(vec[i]<min(X,Y) or vec[i]>max(X,Y)){
                i++;
                left = vec.size()-1;
                continue;
            }
            if(vec[j]<min(X,Y) or vec[j]>max(X,Y)){
                j--;
                right = 1;
                continue;
            }
            
            if( vec[i]>=min(X,Y) and vec[i]<=max(X,Y) ){
                left = min( left,i);   
            }
            if(vec[j]>=min(X,Y) and vec[j]<=max(X,Y)){
                right = max( right, j);
            }
            
            i++;
            j--;
        }
        if( j==i )
            cout<<0<<endl;
        else
            cout<<(right-left+1)<<endl;
        t--;
    }
    return 0;
}
