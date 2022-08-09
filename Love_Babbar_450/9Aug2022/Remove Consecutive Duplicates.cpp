string removeDuplicate(string &s){
    string temp = "";
    temp += s[0];
    int n = s.size();
    for( int i=0; i<n-1; i++ )
        if( s[i] != s[i+1] )
            temp += s[i+1];
   
    return temp;
}
