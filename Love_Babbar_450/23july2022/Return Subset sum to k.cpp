// CPP DSA Lecture 2
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int helper(int input[], int n,int start, int output[][50], int k) {
	if(start==n){	// Base case 
        if(k==0){
            output[0][0]=0;
            return 1;
        }
    else 
        return 0;
    }
    int small1[1000][50];
    int small2[1000][50];
    int size1, size2, row=0;
    size1=helper(input, n, start+1, small1, k);	// Excluding the current element 
    size2=helper(input, n, start+1, small2, k-input[start]);// Including the current element 
   
    for(int i=0;i<size1;i++){
        for(int j=0;j<=small1[i][0];j++)	// Because 0th column of each row holds the the length of each row
            output[row][j]=small1[i][j];	//coying the small array to the output array
    	row++;
    }
    for(int i=0;i<size2;i++){
        output[row][0]=small2[i][0]+1;	//Placing the total number of elements at 0th index of each row
        output[row][1]=input[start];	//Inserting new element at 0th index
        for(int j=1;j<=small2[i][0];j++)
            output[row][j+1]=small2[i][j];	// NOw copying the whole small arrray in the output sarray starting from 2nd indexstarting of each row
    	row++;
    }
    return row;
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	return helper(input,n,0,output,k);
}
