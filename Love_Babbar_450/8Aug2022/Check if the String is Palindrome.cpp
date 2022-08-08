
#include <vector>
bool checkPalindrome(string s){
    int n = s.length();
    vector<char> v; 
    for( int i=0; i<n; i++){
        if( (s[i]>=97 && s[i]<=122) || s[i]>=65 && s[i]<=90 || s[i]>=48 && s[i]<=57 ){
            v.push_back(s[i]);
        }
    }
    int size = v.size()-1;
//     for( int i=0; i<=size; i++){
//         std::cout<<v[i];
//     }
    
    for( int i=0; i<size; i++, size--){
        if( tolower(v[i])!= tolower(v[size]) )
            return false;        
    }
    return true;
}
