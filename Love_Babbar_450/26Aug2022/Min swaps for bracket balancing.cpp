// CPP DSA Love Babbar 450
int miniNumSwaps(string brackets, int n){
        int brkt = 0, cnt = 0;
        for( int  i=0 ;i<n; i++ ){
            if( S[i] ==')' )
                brkt++;
            if( S[i] =='(' )
                brkt--;
        if(brkt > 0 && S[i] == ')') 
            cnt += brkt;
    }
    return cnt;
}
