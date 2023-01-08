// CPP DSA Love Babbar 450
class Solution {
public:
    int minAddToMakeValid(string str) {
        // maintain balance of string
    int bal = 0;
    int ans = 0;
 
    for (int i = 0; i < str.length(); ++i) {
        if( str[i]=='(' )
            bal++;
        else
            bal--;// -ve bal represents we need to add '(' 
                  // +ve bal represents we need to add ')'  
        // It is guaranteed bal >= -1
        if (bal == -1) {
            ans += 1;
            bal += 1;// amking balance zero again as we have counted the deficiency of one '(' in ans 
        }
    }
    return bal + ans;    
    }
};
