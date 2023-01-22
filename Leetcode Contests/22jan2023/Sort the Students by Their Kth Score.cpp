class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, vector<int>> mp;        
        int m = score.size();
        int n = score[0].size();
        for( int i=0; i<m; i++ )
            mp[score[i][k]] = score[i];
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        int j = m-1;
        for ( auto x : mp ){
            for( int i=0; i<n; i++ )
                ans[j][i] = x.second[i];
            
            j--;
        }
        return ans;
    }
};
