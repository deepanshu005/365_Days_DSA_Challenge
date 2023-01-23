class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> trusts;
        unordered_map<int,int> trustedBy;
        int ans = -1;
        int k = trust.size();
        for( int i=0; i<k; i++ ){
            trusts[trust[i][0]]++;
            trustedBy[trust[i][1]]++;
        }
        for( int i=1; i<=n; i++ ){
            if( trusts[i]==0 and trustedBy[i] == n-1){
                ans = i;
            }
        }
        return ans;
    }
};
