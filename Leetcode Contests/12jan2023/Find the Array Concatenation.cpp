class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        long long ans = 0;
        while( i<j ){
            string str = to_string(nums[i++]) + to_string(nums[j--]);
            ans += stoi(str);
        }
        if( i==j )
            ans += nums[i];
        return ans;
    }
};
