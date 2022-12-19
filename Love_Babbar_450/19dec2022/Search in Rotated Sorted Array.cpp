// CPP DSA Love Babbar 450
class Solution {
    int BS( vector<int> &arr, int i, int j, int x ){
        int mid = i + (j-i)/2;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( arr[mid]==x )
                return mid;
            if( arr[mid]>x )
                j = mid-1;
            else 
                i = mid+1;
        }
        return -1;
    }
    int min_index( vector<int> &arr, int i, int j ){
        int n = arr.size();
        int mid = i + (j-i)/2;
        int prev;
        int next;
        while( i<=j ){
            mid = i + (j-i)/2;
            prev = (mid+n-1)%n;
            next = (mid+1)%n;
            if( arr[mid]<=arr[next] and arr[mid]<=arr[prev] ){
                return mid;
            }
            if( arr[mid]>=arr[0] ){
                i = mid+1;
            }
            else if( arr[mid] <= arr[n-1] ){
                j = mid-1;
            }
        }
        return 0;
    }
public:
    int search(vector<int>& nums, int x) {
        int n = nums.size();
        if( nums[0]<=nums[n-1] ){
            return BS( nums, 0, n-1, x);
        }
        int pivot = min_index( nums, 0, n-1 );
        if( nums[pivot]==x )
            return pivot;
        int left = BS( nums, 0, pivot-1, x);
        int right = BS( nums, pivot, n-1, x);
        if( left==-1 )
            return right;
        return left;
    }
};
