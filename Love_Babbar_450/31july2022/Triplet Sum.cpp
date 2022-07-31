// CPP DSA CN Lec-5
// This approach handles duplicacy in oshhm manner
int tripletSum(int *arr, int n, int num)
{
	int count=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){  // extra loop to traverse whole array one by one
        int low=i+1;
        int high=n-1;
        while(low<high){    //exactly same as pair sum problem's approach
            int curr = arr[i]+arr[low]+arr[high];
            if(curr==num){
                int p = low;
                while(p<high && arr[i]+arr[p]+arr[high]==num){
                    count++;
                    p++;
                }
                high--;
            }
            else if (curr<num)
                low++;
            else
                high--;
        }
    }
    return count;
}
