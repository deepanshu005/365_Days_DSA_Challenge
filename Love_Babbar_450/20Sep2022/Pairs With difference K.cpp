//CPP DSA CN Lec 18 Love Babbar 450
#include<unordered_map>
int getPairsWithDifferenceK(int *a, int n, int k) 
{
    unordered_map<int,int>p;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int r=a[i]+k;
        count+=p[r];
        if(k!=0)
        {
            r=a[i]-k;
            count+=p[r];
        }
        p[a[i]]++;
    }
   return count; 
}
/*#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> map;
    int Tcount = 0;
    for( int i=0; i<n; i++ )
        map[arr[i]]++;
    for( int i=0; i<n; i++ ){
        if(map.count(arr[i]+k)>0){
            Tcount++;
            map[arr[i]]--;
            map[arr[i]+k]--;
        }
        if(map.count(arr[i]-k)>0){
            Tcount++;
            map[arr[i]]--;
            map[arr[i]-k]--;
        }
    }
    return Tcount;
}
if(map.count(arr[i]-k)>0&&r>0&&k!=0)
*/
