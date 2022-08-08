
string stringReverse(string S) {
    int n = S.length();
    int k = n-1;
    for( int i=0; i<k; i++, k--)
        swap(S[i], S[k]);
    return S;
}
