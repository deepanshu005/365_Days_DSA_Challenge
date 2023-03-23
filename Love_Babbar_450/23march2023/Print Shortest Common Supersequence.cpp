// CPP DSA Love Babbar 450
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int x = s1.length();
        int y = s2.length();
        vector<vector<int>> dp( x+1, vector<int>(y+1,-1));
        
        for( int i=0; i<=x; i++ ){
            for( int j=0; j<=y; j++ )   {
                if( i==0 or j==0 )
                    dp[i][j] = 0;
                else{
                    if( s1[i-1] == s2[j-1] )
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else if(s1[i-1] != s2[j-1] )
                        dp[i][j] = max( dp[i][j-1], dp[i-1][j] );   
                }
            }
        }
        string str = "";
        int i = x;
        int j = y;        
        while( i>0 and j>0 ){
            if( s1[i-1] == s2[j-1] ){
                str += s1[i-1];
                i--;
                j--;
            }
            else{
                if( dp[i][j-1] > dp[i-1][j] ){// left wala bda h
                    str += s2[j-1];
                    j--;
                }
                else{
                    str += s1[i-1];
                    i--;
                }
            }
        }
        while( i>0 ){
            str += s1[i-1];
            i--;
        }
        while( j>0 ){
            str += s2[j-1];
            j--;
        }
        reverse( str.begin(), str.end() );
        return str;
    }
};
