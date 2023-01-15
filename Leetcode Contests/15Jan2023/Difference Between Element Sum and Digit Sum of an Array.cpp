// CPP DSA Leetcode Contest
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0;
        int digSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++ ){
            eleSum += nums[i];
            int temp = nums[i];
            while(temp){
                digSum += temp%10;
                temp = temp/10;
            }
        }
        return abs(eleSum-digSum);
    }
};
