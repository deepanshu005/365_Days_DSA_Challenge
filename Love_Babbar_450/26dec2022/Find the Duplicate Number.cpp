// CPP DSA Love Babbar 450
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int k = nums.size();
        int n = k-1;// mtlb ydi size 5 h to hr term 1 to 4 hi rhegi
        int sum = 0;
        for( int i=0; i<k; i++ ){
            sum+=nums[i];
        }
        int aSum = n*(n+1)/2;
        return sum-aSum;
    }
};
