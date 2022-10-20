// This is the first question of Codethru 1.0, held on 20Oct2022
//I was able to complete just one question
/*Today is Rakhi and Savlon totally forgot about it. So, he is roaming outside. But after realising this, he now plans to go home soon. Aish is looking for Savlon to tie rakhi.
  Both of them are currently on a straight road which even connects House of Savlon. 
  You know S - Savlon's current coordinate, A - Aish's current coordinate and H-coordinate of Savlon's House. 
  Both Savlon and Aish are heading to Savlon's house with same speed. If Savlon reaches his home strictly before Aish,
  then he will hide there otherwise Aish will tie her Rakhi if they meet in the path. Find out whether Aish can tie Savlon a rakhi or not.

Input Format

The first line of the input contains an integer t — the number of test cases. Then t lines follow, each containing 3 integers S , A , H . S: Savlon's current coordinate A: Aish's current coordinate H: coordinate of Savlon's House

Constraints

1≤ t ≤10^5 -10^9<= H,S,A <=10^9

Output Format

For each test case, output "AISH" if Aish is able to tie savlon a rakhi, otherwise print "SAVLON" on a new line each. NOTE: The Output is CASE-SENSITIVE.
*/
// Solution
#include <iostream>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t>0){
        long long S, A, H;
        cin>>S>>A>>H;
        
        if( abs(S-H)>=abs(A-H) )
            cout<<"AISH"<<endl;
        else
        cout<<"SAVLON"<<endl;
        t--;
    }
}
