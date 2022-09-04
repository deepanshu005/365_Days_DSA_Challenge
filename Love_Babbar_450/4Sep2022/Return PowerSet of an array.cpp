// Love Babar Approach ( including and excluding )

class Solution {
private:
    void solve( vector<int>& nums, vector<int> temp, int index, vector<vector<int>>& ans){
        if( index >= nums.size()){
            ans.push_back(temp);
            return;
        }
        solve( nums, temp, index+1, ans);// excluding integer at nums[index]
        
        temp.push_back( nums[index] );
        solve( nums, temp, index+1, ans);// including integer at nums[index]
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve( nums, temp, 0, ans );
        return ans;
    }
};







// Coding ninjas Approach ( copying the previous ones )

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don't print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
	if( n==0 ){		// BAse case Since there is one element in output array
		output[0][0]=0;
        return 1;	// Its commonsense if we have returned 0 then the function got vanished just after base case coz at last line we have returned 2*SmallOutput which eventually remains zero
    }
    int SmallOutput = subset( input+1, n-1, output );
    for(int i = 0; i<SmallOutput; i++ ){
        int num = output[i][0];	//Num will help in storing the total number of elements in each subset
        output[i+SmallOutput][0] = 1 + num;	// Placing the total number of elements in 0th column of every row
        output[i+SmallOutput][1] = input[0];	//Adding the current new element
        
        for(int j = 1; j<num+1; j++){
            output[i+SmallOutput][j+1] = output[i][j];	//Copyig the whole previous rows to the new rows diagnolly
        }
    }
	return 2*SmallOutput;	//Since we are making copies hence total will be double the original number of rows
}
    
