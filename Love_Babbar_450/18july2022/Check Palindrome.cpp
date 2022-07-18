DSA Lecture 3 coding ninjas
#include <cstring>
bool helper(char input[], int s, int e)
{
    if( e==1 || e==0)
          return true;
    if( input[s]!=input[e] )
        return false;
    // Tail Recursion , Phle calculations hongi then resursive call
     return helper(input, s+1, e-1);
}
bool checkPalindrome(char input[]) {
    int s=0, e=strlen(input)-1 ;
    return helper(input, s, e );
}


