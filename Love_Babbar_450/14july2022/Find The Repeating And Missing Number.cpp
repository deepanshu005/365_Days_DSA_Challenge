#include<vector>
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int n=nums.size();
    int *count=new int[n+1]();
   
      
    int missing=0,repeating=0;
  	for(int i=0;i<n;i++){
        count[nums[i]]++;
        if(count[i]==2)
			repeating = i;
           
		else if(count[i]==0)
			missing = i;
    }
       return {repeating, missing};
}