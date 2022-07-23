// CPP DSA Lecture 4
void subsetSumToKhelp(int input[], int start, int n, int output[], int osize, int k) {
	if( start==n ){	// Base case
        if(k==0){
           for(int i=0;i<osize;i++)
        		cout<<output[i]<<" ";
        cout<<endl;
        }
        return ;
    }
    int small2[10000],size2=0;
    subsetSumToKhelp( input, start+1, n, output, osize, k);
    if(k>0){
        int i;
        for( i=0;i<osize;i++)
            small2[i]=output[i];
        small2[i]=input[start];
        subsetSumToKhelp(input,start+1, n, small2, osize+1, k-input[start]);
    }
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
	int output[10000];
    subsetSumToKhelp(input, 0, size, output, 0, k);
}
