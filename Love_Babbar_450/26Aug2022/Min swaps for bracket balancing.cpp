// CPP DSA Love Babbar 450(GFG)
int minimumNumberOfSwaps(string S){
        int brkt = 0, cnt = 0;
        int n = S.size();
        for( int  i=0 ;i<n; i++ ){
            if( S[i] ==']' )
                brkt++;
            if( S[i] =='[' )
                brkt--;
        if(brkt > 0 && S[i] == ']') 
            cnt += brkt;
    }
    return cnt;
    }
