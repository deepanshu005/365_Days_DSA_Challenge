class Solution {
public:
    int alternateDigitSum(int n) {
        int temp = n;
        int count = 0;
        int ans = 0;
        while(temp){
            temp = temp/10;
            count++;
        }
        temp = n;
        while(count){
            if(count%2 != 0){// if count is odd then last digit will be positive
                ans += temp%10;
            }
            else{
                ans -= temp%10;
            }
            temp = temp/10;
            count--;
        }
        return ans;
    }
};
