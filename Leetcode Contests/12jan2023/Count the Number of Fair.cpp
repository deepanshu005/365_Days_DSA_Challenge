class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;
        for( int i=0; i<n-1; i++ ){
            for( int j=i+1; j<n; j++ ){
                if( nums[i] + nums[j] >=lower and nums[i] + nums[j] <=upper )
                    count++;
            }
        }
        return count;
    }
};
