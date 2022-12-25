// CPP DSA Love Babbar 450
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = INT_MAX;
        int profit = 0;
        int n = prices.size();
        for( int i=0; i<n; i++ ){
            if( prices[i] < curr ){// means favourable time to buy stock
                curr = prices[i];
            }
            else if( prices[i]-curr > profit ){// means favourable time to buy stock
                profit = prices[i]-curr;
            }
        }
        return profit;
    }
};
